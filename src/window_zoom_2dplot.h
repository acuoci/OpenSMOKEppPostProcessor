#ifndef WINDOW_ZOOM_2DPLOT_H
#define WINDOW_ZOOM_2DPLOT_H

#include <QDialog>
#include "ui_window_zoom_2dplot.h"

class Window_Zoom_2dPlot : public QDialog
{
	Q_OBJECT

public:
	Window_Zoom_2dPlot(QWidget *parent = 0);
	~Window_Zoom_2dPlot();

	void SetMinAndMaxValues(const double min_x, const double max_x, const double min_y, const double max_y);
	void SetCurrentValues(const double min_x, const double max_x, const double min_y, const double max_y);

	const double xmin() const { return ui.doubleSpinBox_xmin->value(); }
	const double xmax() const { return ui.doubleSpinBox_xmax->value(); }
	const double ymin() const { return ui.doubleSpinBox_ymin->value(); }
	const double ymax() const { return ui.doubleSpinBox_ymax->value(); }

private:
	Ui::Window_Zoom_2dPlot ui;
};

#endif // WINDOW_ZOOM_2DPLOT_H
