#ifndef WIDGETLOADDEMO_H
#define WIDGETLOADDEMO_H

#include <QtWidgets/QMainWindow>
#include "ui_widgetloaddemo.h"


class WidgetLoadDemo : public QMainWindow
{
	Q_OBJECT

public:
	WidgetLoadDemo(QWidget *parent = 0);
	~WidgetLoadDemo();

private slots:
	void on_pushButton_showLabels_clicked();

private:
	Ui::WidgetLoadDemoClass ui;

};

#endif // WIDGETLOADDEMO_H
