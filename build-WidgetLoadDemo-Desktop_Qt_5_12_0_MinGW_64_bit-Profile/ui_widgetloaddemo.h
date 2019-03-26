/********************************************************************************
** Form generated from reading UI file 'widgetloaddemo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETLOADDEMO_H
#define UI_WIDGETLOADDEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <containerwidget.h>

QT_BEGIN_NAMESPACE

class Ui_WidgetLoadDemoClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_showLabels;
    QSpacerItem *verticalSpacer;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page_1;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_2;
    ContainerWidget *widget_labelContainer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *WidgetLoadDemoClass)
    {
        if (WidgetLoadDemoClass->objectName().isEmpty())
            WidgetLoadDemoClass->setObjectName(QString::fromUtf8("WidgetLoadDemoClass"));
        WidgetLoadDemoClass->resize(600, 400);
        centralWidget = new QWidget(WidgetLoadDemoClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_4 = new QHBoxLayout(centralWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_showLabels = new QPushButton(groupBox);
        pushButton_showLabels->setObjectName(QString::fromUtf8("pushButton_showLabels"));

        verticalLayout->addWidget(pushButton_showLabels);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_3->addWidget(groupBox);


        horizontalLayout_4->addWidget(frame);

        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Plain);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        stackedWidget = new QStackedWidget(frame_2);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page_1 = new QWidget();
        page_1->setObjectName(QString::fromUtf8("page_1"));
        stackedWidget->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        horizontalLayout_2 = new QHBoxLayout(page_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget_labelContainer = new ContainerWidget(page_2);
        widget_labelContainer->setObjectName(QString::fromUtf8("widget_labelContainer"));

        horizontalLayout_2->addWidget(widget_labelContainer);

        stackedWidget->addWidget(page_2);

        horizontalLayout->addWidget(stackedWidget);


        horizontalLayout_4->addWidget(frame_2);

        WidgetLoadDemoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(WidgetLoadDemoClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 18));
        WidgetLoadDemoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(WidgetLoadDemoClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        WidgetLoadDemoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(WidgetLoadDemoClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        WidgetLoadDemoClass->setStatusBar(statusBar);

        retranslateUi(WidgetLoadDemoClass);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(WidgetLoadDemoClass);
    } // setupUi

    void retranslateUi(QMainWindow *WidgetLoadDemoClass)
    {
        WidgetLoadDemoClass->setWindowTitle(QApplication::translate("WidgetLoadDemoClass", "WidgetLoadDemo", nullptr));
        groupBox->setTitle(QApplication::translate("WidgetLoadDemoClass", "GroupBox", nullptr));
        pushButton_showLabels->setText(QApplication::translate("WidgetLoadDemoClass", "show labels", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetLoadDemoClass: public Ui_WidgetLoadDemoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETLOADDEMO_H
