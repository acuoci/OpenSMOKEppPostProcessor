/*----------------------------------------------------------------------*\
|    ___                   ____  __  __  ___  _  _______                  |
|   / _ \ _ __   ___ _ __ / ___||  \/  |/ _ \| |/ / ____| _     _         |
|  | | | | '_ \ / _ \ '_ \\___ \| |\/| | | | | ' /|  _| _| |_ _| |_       |
|  | |_| | |_) |  __/ | | |___) | |  | | |_| | . \| |__|_   _|_   _|      |
|   \___/| .__/ \___|_| |_|____/|_|  |_|\___/|_|\_\_____||_|   |_|        |
|        |_|                                                              |
|                                                                         |
|   Author: Alberto Cuoci <alberto.cuoci@polimi.it>                       |
|   CRECK Modeling Group <http://creckmodeling.chem.polimi.it>            |
|   Department of Chemistry, Materials and Chemical Engineering           |
|   Politecnico di Milano                                                 |
|   P.zza Leonardo da Vinci 32, 20133 Milano                              |
|                                                                         |
|-------------------------------------------------------------------------|
|                                                                         |
|   This file is part of OpenSMOKE++PostProcessor.                        |
|                                                                         |
|	License                                                           |
|                                                                         |
|   Copyright(C) 2014, 2013  Alberto Cuoci                                |
|   OpenSMOKE++PostProcessor is free software: you can redistribute it    |
|   and/or modify it under the terms of the GNU General Public            |
|   License as published by the Free Software Foundation, either          |
|   version 3 of the License, or (at your option) any later version.      |
|                                                                         |
|   OpenSMOKE++PostProcessor is distributed in the hope that it will be   |
|   useful, but WITHOUT ANY WARRANTY; without even the implied warranty   |
|   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the      |
|   GNU General Public License for more details.                          |
|                                                                         |
|   You should have received a copy of the GNU General Public License     |
|   along with OpenSMOKE++. If not, see <http://www.gnu.org/licenses/>.   |
|                                                                         |
\*-----------------------------------------------------------------------*/

#include "window_profiles.h"

Window_Profiles::Window_Profiles(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.pushButton_Profiles, SIGNAL(released()), this, SLOT(Plot_Profiles()));
	QObject::connect(ui.pushButton_Selectivities, SIGNAL(released()), this, SLOT(Plot_Selectivities()));
	QObject::connect(ui.horizontalSlider_Species, SIGNAL(valueChanged(int)), this, SLOT(UpdateListOfSpeciesY()));	
	QObject::connect(ui.radioButton_Selectivity_Element, SIGNAL(toggled(bool)), this, SLOT(Clicked_Selectivity_Element()));	

	QObject::connect(ui.pushButton_clean_Species, SIGNAL(clicked()), this, SLOT(Clean_Species_List()));	
	QObject::connect(ui.pushButton_clean_Species_Selectivity, SIGNAL(released()), this, SLOT(Clean_Species_Selectivity_List()));	
	QObject::connect(ui.pushButton_clean_Additional, SIGNAL(released()), this, SLOT(Clean_Additional_List()));	
}

Window_Profiles::~Window_Profiles()
{

}

void Window_Profiles::SetDatabase(Profiles_Database* data)
{
	data_ = data;
}

// Additional variables
void Window_Profiles::Prepare()
{
	ui.listWidget_Additional->addItems(data_->string_list_additional);
	ui.listWidget_Species->addItems(data_->string_list_massfractions_sorted);

	QStringList string_list_total = data_->string_list_additional + data_->string_list_massfractions_sorted;
	ui.listWidget_X->addItems(string_list_total);
	ui.listWidget_X->item(0)->setSelected(true);

	ui.listWidget_Species_Selectivity->addItems(data_->string_list_massfractions_sorted);

	for(unsigned int j=0;j<data_->list_of_conversion_species_.size();j++)
	{
		unsigned int index = data_->string_list_additional.size()-data_->list_of_conversion_species_.size() + j;
		QString tmp = data_->string_list_additional[index].mid(11, data_->string_list_additional[index].size()-11);
		ui.comboBox_Conversion->addItem(tmp);
	}

	if (data_->is_kinetics_available_ == true)
	{
		for(unsigned int k=0;k<data_->thermodynamicsMapXML->elements().size();k++)
			ui.comboBox_Elements->addItem(QString::fromStdString(data_->thermodynamicsMapXML->elements()[k]));
	}
	else
	{
		ui.comboBox_Conversion->setEnabled(false);
		ui.comboBox_Elements->setEnabled(false);
		ui.pushButton_clean_Species_Selectivity->setEnabled(false);
		ui.pushButton_Selectivities->setEnabled(false);
		ui.radioButton_Selectivity_Element->setEnabled(false);
		ui.radioButton_Selectivity_Mass->setEnabled(false);
		ui.radioButton_Selectivity_Mole->setEnabled(false);
	}
}

void Window_Profiles::Plot_Profiles()
{
	// Find the right x variable, together with the x axis lable
	QVector<double> axis_x;
	QString axis_x_title;
	FindXVariable(axis_x, axis_x_title);

	// XY Plot
	XYPlot* xyplot;
	xyplot = new XYPlot(this);
	xyplot->SetAbscissas(axis_x);
	xyplot->SetXTitle(axis_x_title);
	
	// Select additional y variables
	unsigned int n_selected_additional;
	{
		QList<QListWidgetItem*> selected_additional = ui.listWidget_Additional->selectedItems();
		n_selected_additional = selected_additional.size();
		for(unsigned int j=0;j<n_selected_additional;j++)
		{
			for(unsigned int k=0;k<data_->string_list_additional.size();k++)
			if (selected_additional[j]->text() == data_->string_list_additional[k])
			{
				xyplot->AddGraph(selected_additional[j]->text().toStdString(), data_->additional[k]);
				break;
			}
		}	
	}

	// Select y variables among the species
	{
		QList<QListWidgetItem*> selected_species = ui.listWidget_Species->selectedItems();
		unsigned int n_selected_species = selected_species.size();
		if (n_selected_species == 0 && n_selected_additional == 0)
		{
			QMessageBox msgBox;
			msgBox.setText(QString::fromStdString("At least one species must be selected in the Species Panel"));
			msgBox.exec();
			return;
		}

		for(unsigned int j=0;j<n_selected_species;j++)
		{
			for(unsigned int k=0;k<data_->string_list_massfractions_sorted.size();k++)
			if (selected_species[j]->text() == data_->string_list_massfractions_sorted[k])
			{
				QVector<double> tmp = data_->omega[data_->sorted_index[k]];
				const double mwj = data_->mw_species_[data_->sorted_index[k]];
			
				if (ui.radioButton_x->isChecked())
				{
					for(unsigned int i=0;i<data_->number_of_abscissas_;i++)
						tmp[i] = tmp[i] * data_->additional[data_->index_MW][i] / mwj;
				}
				else if (ui.radioButton_c->isChecked())
				{
					for(unsigned int i=0;i<data_->number_of_abscissas_;i++)
					{
						double cTot = data_->additional[data_->index_P][i]/PhysicalConstants::R_J_kmol/data_->additional[data_->index_T][i];
						tmp[i] = cTot * tmp[i] * data_->additional[data_->index_MW][i] / mwj;
					}
				}
				else if (ui.radioButton_p->isChecked())
				{
					for(unsigned int i=0;i<data_->number_of_abscissas_;i++)
						tmp[i] = tmp[i] * data_->additional[data_->index_MW][i] / mwj * (data_->additional[data_->index_P][i]/101325.);
				}

				xyplot->AddGraph(selected_species[j]->text().toStdString(), tmp);
				break;
			}
		}
	}

	// Plot
	xyplot->Plot();
}

void Window_Profiles::UpdateListOfSpeciesY()
{
	const double slider_position = double(ui.horizontalSlider_Species->value()) / double(ui.horizontalSlider_Species->maximum()) * 100;
	//const double threshold = 2.1100*(exp(0.03879369254481392*slider_position)-1.) / 100.;
	const double threshold = 0.1006*(exp(0.06903072535586566*slider_position)-1.) / 100.;
	
	ui.listWidget_Species->clear();
	if (ui.horizontalSlider_Species->value() == 0)
	{
		ui.listWidget_Species->addItems(data_->string_list_massfractions_sorted);
	}
	else
	{
		data_->SpeciesCoarsening(threshold);
		QStringList current_string_list;
		current_string_list.reserve(data_->current_sorted_index.size());
		for (unsigned int k=0;k<data_->current_sorted_index.size();k++)
			current_string_list.push_back(data_->string_list_massfractions_sorted[data_->current_sorted_index[k]]);
		ui.listWidget_Species->addItems(current_string_list);
	}
}

void Window_Profiles::Clean_Species_List()
{
	for(int index = 0; index < ui.listWidget_Species->count(); index++)
	{
		if (ui.listWidget_Species->item(index)->isSelected() == true)
			ui.listWidget_Species->item(index)->setSelected(false);
	}
}

void Window_Profiles::Clean_Species_Selectivity_List()
{
	for(int index = 0; index < ui.listWidget_Species_Selectivity->count(); index++)
	{
		if (ui.listWidget_Species_Selectivity->item(index)->isSelected() == true)
			ui.listWidget_Species_Selectivity->item(index)->setSelected(false);
	}
}

void Window_Profiles::Clean_Additional_List()
{
	for(int index = 0; index < ui.listWidget_Additional->count(); index++)
	{
		if (ui.listWidget_Additional->item(index)->isSelected() == true)
			ui.listWidget_Additional->item(index)->setSelected(false);
	}
}

void Window_Profiles::Plot_Selectivities()
{
	// Find the right x variable, together with the x axis lable
	QVector<double> axis_x;
	QString axis_x_title;
	FindXVariable(axis_x, axis_x_title);

	// XY Plot
	XYPlot* xyplot;
	xyplot = new XYPlot(this);
	xyplot->SetXTitle(axis_x_title);
	xyplot->SetYTitle("selectivity [-]");

	// Find the species for the conversion
	unsigned int index_species_conversion = data_->list_of_conversion_species_[ui.comboBox_Conversion->currentIndex()];

	// If the conversion is too small, the sensitivity coefficient is badly defined
	// Therefore the calculation is skipped in those points
	const double eta_threshold = 1.e-6;
	QVector<double> omega_conversion = data_->omega[index_species_conversion];
	QVector<double> eta_x;
	for(unsigned int i=0;i<data_->number_of_abscissas_;i++)
	{
		const double conversion = (omega_conversion[0] - omega_conversion[i])/omega_conversion[0];
		if (conversion > eta_threshold)	
				eta_x.push_back(axis_x[i]);
	}
	xyplot->SetAbscissas(eta_x);

	// Reconstruct the profiles
	{
		QList<QListWidgetItem*> selected_species_selectivity = ui.listWidget_Species_Selectivity->selectedItems();
		unsigned int n_selected_species = selected_species_selectivity.size();
		if (n_selected_species == 0)
		{
			QMessageBox msgBox;
			msgBox.setText(QString::fromStdString("At least one species must be selected in the Species (Selectivity) Panel"));
			msgBox.exec();
			return;
		}

		for(unsigned int j=0;j<n_selected_species;j++)
		{
			for(unsigned int k=0;k<data_->string_list_massfractions_sorted.size();k++)
			if (selected_species_selectivity[j]->text() == data_->string_list_massfractions_sorted[k])
			{
				unsigned int index_selectivity = data_->sorted_index[k];
				
				QVector<double> sigma;
				for(unsigned int i=0;i<data_->number_of_abscissas_;i++)
				{
					const double conversion = (omega_conversion[0] - omega_conversion[i])/omega_conversion[0];
					if (conversion > eta_threshold)
						sigma.push_back(data_->omega[index_selectivity][i]/omega_conversion[0]/conversion);
				}

				if (ui.radioButton_Selectivity_Mole->isChecked() == true)
				{
					const double mw_conversion = data_->mw_species_[index_species_conversion];
					const double mw_selectivity = data_->mw_species_[index_selectivity];
					for(unsigned int i=0;i<sigma.size();i++)
						sigma[i] *= mw_conversion/mw_selectivity;
				}

				if (ui.radioButton_Selectivity_Element->isChecked() == true)
				{
					const double n_conversion  = data_->thermodynamicsMapXML->atomic_composition()(index_species_conversion, ui.comboBox_Elements->currentIndex());
					const double n_selectivity = data_->thermodynamicsMapXML->atomic_composition()(index_selectivity, ui.comboBox_Elements->currentIndex());

					if (n_conversion > 0)
					{
						const double mw_conversion = data_->mw_species_[index_species_conversion];
						const double mw_selectivity = data_->mw_species_[index_selectivity];
						for(unsigned int i=0;i<sigma.size();i++)
							sigma[i] *= mw_conversion/mw_selectivity *n_selectivity/n_conversion;
					}
					else
					{
						QMessageBox msgBox;
						msgBox.setText(QString::fromStdString("The selected element is not present in the selected species (conversion side)"));
						msgBox.exec();
						return;
					}
				}

				xyplot->AddGraph(selected_species_selectivity[j]->text().toStdString(), sigma);
				break;
			}
		}

		// Plot
		xyplot->Plot();
	}
}

void Window_Profiles::Clicked_Selectivity_Element()
{
	ui.comboBox_Elements->setEnabled(ui.radioButton_Selectivity_Element->isChecked());
}

void Window_Profiles::FindXVariable(QVector<double>& axis_x, QString& axis_x_title)
{
	// Find the right x variable, together with the x axis lable
	QList<QListWidgetItem*> selected_x = ui.listWidget_X->selectedItems();
	if (selected_x.size() == 0)
		return;
	
	for(unsigned int k=0;k<data_->string_list_additional.size();k++)
		if (selected_x[0]->text() == data_->string_list_additional[k])
		{
			axis_x = data_->additional[k];
			axis_x_title = data_->string_list_additional[k];
			break;
		}
	
	if (axis_x.size() == 0)
	{
		for(unsigned int k=0;k<data_->string_list_massfractions_sorted.size();k++)
			if (selected_x[0]->text() == data_->string_list_massfractions_sorted[k])
			{
				axis_x = data_->omega[data_->sorted_index[k]];
				const double mwj = data_->mw_species_[data_->sorted_index[k]];
			
				if (ui.radioButton_x->isChecked())
				{
					for(unsigned int i=0;i<data_->number_of_abscissas_;i++)
						axis_x[i] = axis_x[i] * data_->additional[data_->index_MW][i] / mwj;
				}
				else if (ui.radioButton_c->isChecked())
				{
					for(unsigned int i=0;i<data_->number_of_abscissas_;i++)
					{
						double cTot = data_->additional[data_->index_P][i]/PhysicalConstants::R_J_kmol/data_->additional[data_->index_T][i];
						axis_x[i] = cTot * axis_x[i] * data_->additional[data_->index_MW][i] / mwj;
					}
				}
				else if (ui.radioButton_p->isChecked())
				{
					for(unsigned int i=0;i<data_->number_of_abscissas_;i++)
						axis_x[i] = axis_x[i] * data_->additional[data_->index_MW][i] / mwj * (data_->additional[data_->index_P][i]);
				}

					
				axis_x_title = data_->string_list_massfractions_sorted[k];
				break;
			}
	}
}

