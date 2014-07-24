#ifndef WINDOW_SENSITIVITIES_H
#define WINDOW_SENSITIVITIES_H

#include <QWidget>
#include "ui_window_sensitivities.h"

class Profiles_Database;
class Sensitivities_Database;

class Window_Sensitivities : public QWidget
{
	Q_OBJECT

public:
	Window_Sensitivities(QWidget *parent = 0);
	~Window_Sensitivities();

public:

	void SetDatabase(Profiles_Database* data);
	void Prepare();

private:
	Ui::Window_Sensitivities ui;

	Profiles_Database* data_;
	Sensitivities_Database* sensitivities;

private slots:

	void Clean_Reactions_List();

	void Plot_Sensitivities_Profiles();
	void Plot_Sensitivities_BarChart();

	void Clicked_Sensitivities_Local();
	void Clicked_Sensitivities_Region();
	void Clicked_Sensitivities_Global();

	void UpdateListOfReactions();
	void ReadSensitvityCoefficients();
};

//#include "window_sensitivities.cpp"

#endif // WINDOW_SENSITIVITIES_H
