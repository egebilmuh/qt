#ifndef CONTAINERWIDGET_H
#define CONTAINERWIDGET_

#include <QWidget>
#include "ui_containerwidget.h"

#include <QLabel>
#include <QlineEdit>
#include <QList>

class ContainerWidget : public QWidget
{
	Q_OBJECT

public:
	ContainerWidget(QWidget *parent = 0);
	~ContainerWidget();
	void setTexts(int index);

private:
	Ui::ContainerWidget ui;
	QList<QLabel*> list;
};

#endif // CONTAINERWIDGET_H
