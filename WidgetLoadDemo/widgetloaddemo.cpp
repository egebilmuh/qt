#include "widgetloaddemo.h"


#include <QTime>
#include <iostream>

using namespace std;
WidgetLoadDemo::WidgetLoadDemo(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.stackedWidget->setCurrentIndex(0);
}

WidgetLoadDemo::~WidgetLoadDemo()
{

}

void WidgetLoadDemo::on_pushButton_showLabels_clicked()
{
	static int index = 0;
	index = (index +1)%2;
	QTime t;
	t.start();
// 	if (index > 0)
// 	{
// 		ui.frame_2->setFocus();
// 	}
// 	else
// 		ui.frame->setFocus();
	ui.widget_labelContainer->setTexts(index);
	qApp->processEvents();
	ui.stackedWidget->setCurrentIndex(index);
	qApp->processEvents();
	cout << "elapsed time: " << t.elapsed() << endl;

	
}
