#include "window_sensitivities.h"

#include "Profiles_Database.h"
#include "Sensitivities_Database.h"
#include "Utilities.h"

#include "qcustomplot.h"
#include "xyplot.h"
#include <QMessageBox>
#include <sstream>
#include "widget_horizontal_bars.h"
#include <Eigen/Dense>
#include <sstream>

Window_Sensitivities::Window_Sensitivities(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	QObject::connect(ui.pushButton_Sensitivities_PlotProfiles, SIGNAL(released()), this, SLOT(Plot_Sensitivities_Profiles()));
	QObject::connect(ui.pushButton_Sensitivities_BarChart, SIGNAL(released()), this, SLOT(Plot_Sensitivities_BarChart()));
	
	QObject::connect(ui.radioButton_Sensitivities_Local, SIGNAL(toggled(bool)), this, SLOT(Clicked_Sensitivities_Local()));	
	QObject::connect(ui.radioButton_Sensitivities_Region, SIGNAL(toggled(bool)), this, SLOT(Clicked_Sensitivities_Region()));
	QObject::connect(ui.radioButton_Sensitivities_Global, SIGNAL(toggled(bool)), this, SLOT(Clicked_Sensitivities_Global()));

	QObject::connect(ui.pushButton_clean_Reactions, SIGNAL(clicked()), this, SLOT(Clean_Reactions_List()));
	QObject::connect(ui.horizontalSlider_Sensitivities_Reactions, SIGNAL(valueChanged(int)), this, SLOT(UpdateListOfReactions()));	

	QObject::connect(ui.listWidget_Sensitivities_Y, SIGNAL(itemSelectionChanged()), this, SLOT(ReadSensitvityCoefficients()));	
}

Window_Sensitivities::~Window_Sensitivities()
{

}

void Window_Sensitivities::SetDatabase(Profiles_Database* data)
{
	data_ = data;
}

void Window_Sensitivities::Prepare()
{
	sensitivities = new Sensitivities_Database();
	sensitivities->SetDatabase(data_);
	sensitivities->ReadParentFile();

	// Widget: reactions
	{
		sensitivities->ReactionsReset();
		ui.listWidget_Sensitivities_Reactions->addItems(sensitivities->string_list_reactions());
	}

	// Widget: variables y
	{
		QStringList string_list_variables_y;
		string_list_variables_y.reserve(sensitivities->number_of_variables());
		for(unsigned int j=0;j<sensitivities->number_of_variables();j++)
			string_list_variables_y.push_back(QString::fromStdString(sensitivities->names()[j]));
		ui.listWidget_Sensitivities_Y->addItems(string_list_variables_y);
	}

	// Widget: variables x
	{
		ui.comboBox_Sensitivities_X->addItem(data_->string_list_additional[0]);
	}


	ui.doubleSpinBox_Sensitivities_Local->setMaximum(data_->additional[0][data_->number_of_abscissas_-1]);
	ui.doubleSpinBox_Sensitivities_Local->setMinimum(data_->additional[0][0]);
	ui.doubleSpinBox_Sensitivities_Local->setValue(0.50*(data_->additional[0][0]+data_->additional[0][data_->number_of_abscissas_-1]));

	ui.doubleSpinBox_Sensitivities_Region_Min->setMaximum(data_->additional[0][data_->number_of_abscissas_-1]);
	ui.doubleSpinBox_Sensitivities_Region_Min->setMinimum(data_->additional[0][0]);
	ui.doubleSpinBox_Sensitivities_Region_Min->setValue(data_->additional[0][0]);

	ui.doubleSpinBox_Sensitivities_Region_Max->setMaximum(data_->additional[0][data_->number_of_abscissas_-1]);
	ui.doubleSpinBox_Sensitivities_Region_Max->setMinimum(data_->additional[0][0]);
	ui.doubleSpinBox_Sensitivities_Region_Max->setValue(data_->additional[0][data_->number_of_abscissas_-1]);

	ui.comboBox_Sensitivities_Integral->addItem("Peak values");
	ui.comboBox_Sensitivities_Integral->addItem("Area");
	ui.comboBox_Sensitivities_Integral->addItem("Absolute Area");
}

void Window_Sensitivities::Clicked_Sensitivities_Local()
{
	ui.doubleSpinBox_Sensitivities_Local->setEnabled(true);
	ui.doubleSpinBox_Sensitivities_Region_Min->setEnabled(false);
	ui.doubleSpinBox_Sensitivities_Region_Max->setEnabled(false);
}

void Window_Sensitivities::Clicked_Sensitivities_Region()
{
	ui.doubleSpinBox_Sensitivities_Local->setEnabled(false);
	ui.doubleSpinBox_Sensitivities_Region_Min->setEnabled(true);
	ui.doubleSpinBox_Sensitivities_Region_Max->setEnabled(true);
}

void Window_Sensitivities::Clicked_Sensitivities_Global()
{
	ui.doubleSpinBox_Sensitivities_Local->setEnabled(false);
	ui.doubleSpinBox_Sensitivities_Region_Min->setEnabled(false);
	ui.doubleSpinBox_Sensitivities_Region_Max->setEnabled(false);
}

void Window_Sensitivities::Clean_Reactions_List()
{
	for(int index = 0; index < ui.listWidget_Sensitivities_Reactions->count(); index++)
	{
		if (ui.listWidget_Sensitivities_Reactions->item(index)->isSelected() == true)
			ui.listWidget_Sensitivities_Reactions->item(index)->setSelected(false);
	}
}

void Window_Sensitivities::Plot_Sensitivities_Profiles()
{
	bool iLocalNormalization = true;
	if (ui.radioButton__Sensitivities_NormalizeMax->isChecked() == true)
		iLocalNormalization = false;

	QList<QListWidgetItem*> selected_y = ui.listWidget_Sensitivities_Y->selectedItems();
	if (selected_y.size() == 0)
	{
		QMessageBox msgBox;
		msgBox.setText(QString::fromStdString("You have to select one of the available Y variables"));
		msgBox.exec();
		return;
	}

	QList<QListWidgetItem*> selected_reactions = ui.listWidget_Sensitivities_Reactions->selectedItems();
	if (selected_reactions.size() == 0)
	{
		QMessageBox msgBox;
		msgBox.setText(QString::fromStdString("You have to select at least one of the available reactions"));
		msgBox.exec();
		return;
	}

	std::vector<int> selected_reaction_indices;
	for(int index = 0; index < ui.listWidget_Sensitivities_Reactions->count(); index++)
	{
		if (ui.listWidget_Sensitivities_Reactions->item(index)->isSelected() == true)
			selected_reaction_indices.push_back(index);
	}

	XYPlot* plot = new XYPlot(this);
	plot->SetAbscissas(data_->additional[0]);
	
	for(unsigned int k=0;k<selected_reaction_indices.size();k++)
	{
		QString name = ui.listWidget_Sensitivities_Reactions->item(selected_reaction_indices[k])->text();
		plot->AddGraph(name.toStdString(), sensitivities->NormalizedProfile(sensitivities->current_coarse_index()[selected_reaction_indices[k]]-1, iLocalNormalization));
	}
	plot->Plot();
}

void Window_Sensitivities::Plot_Sensitivities_BarChart()
{
	bool iLocalNormalization = true;
	if (ui.radioButton__Sensitivities_NormalizeMax->isChecked() == true)
		iLocalNormalization = false;

	QList<QListWidgetItem*> selected_y = ui.listWidget_Sensitivities_Y->selectedItems();
	if (selected_y.size() == 0)
	{
		QMessageBox msgBox;
		msgBox.setText(QString::fromStdString("You have to select one of the available Y variables"));
		msgBox.exec();
		return;
	}

	if (ui.radioButton_Sensitivities_Local->isChecked() == true)
	{
		// Find the point index
		unsigned int index = 0;
		for(unsigned int j=0;j<data_->number_of_abscissas_;j++)
			if (data_->additional[0][j] >= ui.doubleSpinBox_Sensitivities_Local->value() )
			{
				index = j;
				break;
			}

		// Fill the reaction indices
			std::vector<unsigned int> total_indices(sensitivities->number_of_parameters());
		for (unsigned int j=0;j<sensitivities->number_of_parameters();j++)
			total_indices[j] = j+1;

		// Evaluates the coefficients
		std::vector<double> total_coefficients(sensitivities->number_of_parameters());
		for (unsigned int j=0;j<sensitivities->number_of_parameters();j++)
			total_coefficients[j] = sensitivities->NormalizedProfile(j, iLocalNormalization, index);

		// Reorder the coefficients
		std::vector<int> indices;
		std::vector<double> coefficients;
		MergeBars( total_indices, total_coefficients, indices, coefficients);

		// Fill the vector containing the reaction strings
		std::vector<std::string> reaction_names(indices.size());
		for(unsigned int i=0;i<indices.size();i++)
			reaction_names[i] = sensitivities->string_list_reactions()[indices[i]-1].toStdString();

		// Plot the bars
		Widget_Horizontal_Bars* horizontal_bars = new Widget_Horizontal_Bars();
		horizontal_bars->setTitle("Sensitivity Analysis");
		horizontal_bars->setMainComment("Sensitivity Analysis - " + selected_y[0]->text());
		horizontal_bars->setRectangles(	coefficients, indices, reaction_names);
		horizontal_bars->show();
	}

	else 
	{
		unsigned int index_min = 0;
		unsigned int index_max = data_->number_of_abscissas_-1;
		if (ui.radioButton_Sensitivities_Region->isChecked() == true)
		{
			for(unsigned int j=0;j<data_->number_of_abscissas_;j++)
				if (data_->additional[0][j] >= ui.doubleSpinBox_Sensitivities_Region_Min->value() )
				{
					index_min = j;
					break;
				}

			for(unsigned int j=index_min;j<data_->number_of_abscissas_;j++)
				if (data_->additional[0][j] >= ui.doubleSpinBox_Sensitivities_Region_Max->value() )
				{
					index_max = j;
					break;
				}

			if (index_min == index_max)
			{
				if (index_max == data_->number_of_abscissas_-1)
					index_min = index_max-1;
				else
					index_max = index_min+1;
			}
		}


		const double delta = data_->additional[0][index_max] - data_->additional[0][index_min];

		// Fill the reaction indices
		std::vector<unsigned int> total_indices(sensitivities->number_of_parameters());
		for (unsigned int j=0;j<sensitivities->number_of_parameters();j++)
			total_indices[j] = j+1;

		// Evaluates the coefficients
		std::vector<double> total_coefficients(sensitivities->number_of_parameters());
		std::vector<double> total_peaks(sensitivities->number_of_parameters());
		QVector<double> profile(data_->number_of_abscissas_);
		for (unsigned int j=0;j<sensitivities->number_of_parameters();j++)
		{
			profile = sensitivities->NormalizedProfile(j, iLocalNormalization);

			if (ui.comboBox_Sensitivities_Integral->currentIndex() == 0)
			{
				double max_value = -1.e100;
				unsigned int max_index=0;
				for (unsigned int i=index_min;i<index_max;i++)
					if ( fabs(profile[i]) > max_value)
					{
						max_value = fabs(profile[i]);
						max_index = i;
					}
				total_coefficients[j] = profile[max_index];
				total_peaks[j] = data_->additional[0][max_index];
			}
			else if (ui.comboBox_Sensitivities_Integral->currentIndex() == 1)
			{
				double sum = 0;
				for (unsigned int i=index_min;i<index_max-1;i++)
					sum += profile[i]*(data_->additional[0][i+1]-data_->additional[0][i]);
				total_coefficients[j] = sum/delta;
			}
			else if (ui.comboBox_Sensitivities_Integral->currentIndex() == 2)
			{
				double sumPlus = 0;
				double sumMinus = 0;
				for (unsigned int i=index_min;i<index_max-1;i++)
				{
					if (profile[i] < 0.)
						sumMinus -= profile[i]*(data_->additional[0][i+1]-data_->additional[0][i]);
					else
						sumPlus += profile[i]*(data_->additional[0][i+1]-data_->additional[0][i]);
				}
				
				if (sumPlus > sumMinus) total_coefficients[j] =  (sumPlus + sumMinus)/delta;
				else                    total_coefficients[j] = -(sumPlus + sumMinus)/delta;
			}
		}

		// Reorder the coefficients
		std::vector<int> indices;
		std::vector<double> coefficients;
		std::vector<double> peaks;

		if (ui.comboBox_Sensitivities_Integral->currentIndex() == 0)
			MergeBars( total_indices, total_coefficients, total_peaks, indices, coefficients, peaks);
		else
			MergeBars( total_indices, total_coefficients, indices, coefficients);

		// Fill the vector containing the reaction strings
		std::vector<std::string> reaction_names(indices.size());
		for(unsigned int i=0;i<indices.size();i++)
			reaction_names[i] = sensitivities->string_list_reactions()[indices[i]-1].toStdString();

		// Plot the bars
		Widget_Horizontal_Bars* horizontal_bars = new Widget_Horizontal_Bars();
		horizontal_bars->setTitle("Sensitivity Analysis");
		horizontal_bars->setMainComment("Sensitivity Analysis - "  + selected_y[0]->text());

		if (ui.comboBox_Sensitivities_Integral->currentIndex() == 0)
			horizontal_bars->setRectangles(	coefficients, indices, peaks, reaction_names);
		else
			horizontal_bars->setRectangles(	coefficients, indices, reaction_names);
		
		horizontal_bars->show();
	}
}

void Window_Sensitivities::UpdateListOfReactions()
{	
	QList<QListWidgetItem*> selected_y = ui.listWidget_Sensitivities_Y->selectedItems();
	if (selected_y.size() == 0)
	{
		QMessageBox msgBox;
		msgBox.setText(QString::fromStdString("You have to select one of the available Y variables"));
		msgBox.exec();
		return;
	}
		
	ui.listWidget_Sensitivities_Reactions->clear();
	if (ui.horizontalSlider_Sensitivities_Reactions->value() == 0)
	{
		sensitivities->ReactionsReset();
		ui.listWidget_Sensitivities_Reactions->addItems(sensitivities->string_list_reactions());	
	}
	else
	{
		const double slider_position = double(ui.horizontalSlider_Sensitivities_Reactions->value()) / double(ui.horizontalSlider_Sensitivities_Reactions->maximum()) * 100;
		//const double threshold = 2.1100*(exp(0.03879369254481392*slider_position)-1.) / 100.;
		const double threshold = 0.1006*(exp(0.06903072535586566*slider_position)-1.) / 100.;

		sensitivities->ReactionsCoarsening(threshold);
		QStringList current_string_list;
		current_string_list.reserve(sensitivities->current_coarse_index().size());

		for (unsigned int k=0;k<sensitivities->current_coarse_index().size();k++)
			current_string_list.push_back(sensitivities->string_list_reactions()[sensitivities->current_coarse_index()[k]-1]);
		ui.listWidget_Sensitivities_Reactions->addItems(current_string_list);
	}
}

void Window_Sensitivities::ReadSensitvityCoefficients()
{
	QList<QListWidgetItem*> selected_y = ui.listWidget_Sensitivities_Y->selectedItems();
	if (selected_y.size() == 0)
		return;

	sensitivities->ReadFromChildFile(selected_y[0]->text().toStdString());
}

	