#ifndef QBARSWIDGET_H
#define QBARSWIDGET_H

#include <QMap>
#include <QPixmap>
#include <QVector>
#include <QWidget>
#include <vector>

#include "ui_widget_horizontal_bars.h"

class Widget_Horizontal_Bars : public QWidget
{
	Q_OBJECT

public:
	Widget_Horizontal_Bars(QWidget *parent = 0);
	
	void paintEvent(QPaintEvent *event);

	void setTitle(const QString _title);
	void setMainComment(const QString _comment);
	
	void setRectangles(	const std::vector<double>	_r_coordinates,
						const std::vector<int>      _indices,
						const std::vector<QString>	_names);

	void setRectangles(	const std::vector<double>	_r_coordinates,
						const std::vector<int>      _indices,
						const std::vector<double>   _peaks,
						const std::vector<QString>	_names);

	void setRectangles(	const std::vector<double>		_r_coordinates,
						const std::vector<int>			_indices,
						const std::vector<std::string>	_names);

	void setRectangles(	const std::vector<double>		_r_coordinates,
						const std::vector<int>			_indices,
						const std::vector<double>		_peaks,
						const std::vector<std::string>	_names);

	~Widget_Horizontal_Bars();

private:
	
	Ui::Widget_Horizontal_Bars ui;

	int n_rectangles;
	int n_total_rectangles;
	double h_rectangles;
	QString mainComment;

	std::vector<double> r_coordinates;
	std::vector<double> x_coordinates;
	std::vector<double> y_coordinates;

	std::vector<QString> r_strings;
	std::vector<QString> r_indices;
	std::vector<QString> r_peaks;
	std::vector<QString> r_values;

	void setContextMenu();
	void draw(QPainter *painter);
	void setFonts();
	void prepareText(QString *stringText);

	QAction *copyImageAction;
	QAction *printImageAction;

	QAction *copyTextAction;
	QAction *printTextAction;

	QAction *colorAction;

	QFont font_string;
	QFont font_value;
	QFont font_index;

	QColor color_PlusBars;
	QColor color_MinusBars;

	
	

private slots:

	void copyImage();
	void printImage();

	void copyText();
	void printText();

	void setColors();

private:

	static const int	max_bars;
	static const double h_window;
	static const double w_window;
};

#endif // QBARSWIDGET_H
