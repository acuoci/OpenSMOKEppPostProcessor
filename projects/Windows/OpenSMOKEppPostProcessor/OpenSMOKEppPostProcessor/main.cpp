#include "opensmokepppostprocessor.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	OpenSMOKEppPostProcessor w;
	w.show();
	return a.exec();
}
