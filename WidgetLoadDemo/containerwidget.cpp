#include "containerwidget.h"
#include <QGridLayout>
#include <QBoxLayout>

ContainerWidget::ContainerWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setStyleSheet("background-color:red");
	QHBoxLayout* mainLayout = new QHBoxLayout;
	mainLayout->setSpacing(10);
	setLayout(mainLayout);
	for (int i = 0; i < 4; ++i)
	{
		QVBoxLayout* vLayout = new QVBoxLayout;
		vLayout->setSpacing(5);
		mainLayout->addItem(vLayout);
		for (int j = 0; j< 20; ++j)
		{
			QHBoxLayout* hLayout = new QHBoxLayout;
			hLayout->setSpacing(3);
			vLayout->addItem(hLayout);
			for (int k = 0; k < 4; k++)
			{
				QLabel *label = new QLabel(this);
				label->setText(QString::number(i*20+j*4+k));
				label->setFrameStyle(QFrame::Box);
				label->setObjectName("label"+i*20+j*4+k);
				label->setAlignment(Qt::AlignLeft);
				label->setStyleSheet("font-family: Arial; font:12pt; border: 1px solid black;");
				list.append(label);
				label->setFixedWidth(40);
				hLayout->addWidget(label,1);
			}

		}
	}
}

ContainerWidget::~ContainerWidget()
{

}

void ContainerWidget::setTexts(int index)
{
	foreach (QLabel* label , list)
	{
		label->setText(QString::number((label->text().toInt()+index)));
	}
}
