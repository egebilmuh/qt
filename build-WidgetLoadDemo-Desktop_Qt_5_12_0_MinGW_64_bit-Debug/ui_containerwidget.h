/********************************************************************************
** Form generated from reading UI file 'containerwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTAINERWIDGET_H
#define UI_CONTAINERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContainerWidget
{
public:

    void setupUi(QWidget *ContainerWidget)
    {
        if (ContainerWidget->objectName().isEmpty())
            ContainerWidget->setObjectName(QString::fromUtf8("ContainerWidget"));
        ContainerWidget->resize(400, 300);

        retranslateUi(ContainerWidget);

        QMetaObject::connectSlotsByName(ContainerWidget);
    } // setupUi

    void retranslateUi(QWidget *ContainerWidget)
    {
        ContainerWidget->setWindowTitle(QApplication::translate("ContainerWidget", "ContainerWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ContainerWidget: public Ui_ContainerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTAINERWIDGET_H
