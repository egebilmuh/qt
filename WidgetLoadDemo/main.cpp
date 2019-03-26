#include "widgetloaddemo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	WidgetLoadDemo w;
	w.show();
	return a.exec();
}
