#include "window_zoom_2dplot.h"

Window_Zoom_2dPlot::Window_Zoom_2dPlot(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	QObject::connect(ui.pushButton_OK, SIGNAL(released()), this, SLOT(accept()));
	QObject::connect(ui.pushButton_Cancel, SIGNAL(released()), this, SLOT(reject()));
}

Window_Zoom_2dPlot::~Window_Zoom_2dPlot()
{

}

void Window_Zoom_2dPlot::SetMinAndMaxValues(const double min_x, const double max_x, const double min_y, const double max_y)
{
	ui.doubleSpinBox_xmin->setMinimum(min_x);
	ui.doubleSpinBox_xmin->setMaximum(max_x);
	ui.doubleSpinBox_xmax->setMinimum(min_x);
	ui.doubleSpinBox_xmax->setMaximum(max_x);

	ui.doubleSpinBox_ymin->setMinimum(min_y);
	ui.doubleSpinBox_ymin->setMaximum(max_y);
	ui.doubleSpinBox_ymax->setMinimum(min_y);
	ui.doubleSpinBox_ymax->setMaximum(max_y);

	ui.doubleSpinBox_xmin->setDecimals(12);
	ui.doubleSpinBox_xmin->setSingleStep((max_x-min_x)/100.);
	ui.doubleSpinBox_xmax->setDecimals(12);
	ui.doubleSpinBox_xmax->setSingleStep((max_x-min_x)/100.);
	ui.doubleSpinBox_ymin->setDecimals(12);
	ui.doubleSpinBox_ymin->setSingleStep((max_y-min_y)/100.);
	ui.doubleSpinBox_ymax->setDecimals(12);
	ui.doubleSpinBox_ymax->setSingleStep((max_y-min_y)/100.);

}

void Window_Zoom_2dPlot::SetCurrentValues(const double min_x, const double max_x, const double min_y, const double max_y)
{
	ui.doubleSpinBox_xmin->setValue(min_x);
	ui.doubleSpinBox_xmax->setValue(max_x);
	ui.doubleSpinBox_ymin->setValue(min_y);
	ui.doubleSpinBox_ymax->setValue(max_y);
}
