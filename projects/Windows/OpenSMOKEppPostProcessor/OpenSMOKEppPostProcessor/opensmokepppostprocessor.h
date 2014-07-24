#ifndef OPENSMOKEPPPOSTPROCESSOR_H
#define OPENSMOKEPPPOSTPROCESSOR_H

#include <QtWidgets/QMainWindow>
#include "ui_opensmokepppostprocessor.h"

class OpenSMOKEppPostProcessor : public QMainWindow
{
	Q_OBJECT

public:
	OpenSMOKEppPostProcessor(QWidget *parent = 0);
	~OpenSMOKEppPostProcessor();

private:
	Ui::OpenSMOKEppPostProcessorClass ui;
};

#endif // OPENSMOKEPPPOSTPROCESSOR_H
