#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGridLayout *hLayout = new QGridLayout(ui->centralWidget);
    hLayout->addWidget(new QLabel("Label 1",ui->centralWidget),1,1);
    hLayout->addWidget(new QLabel("QLabel 2", ui->centralWidget),1,2);
    hLayout->addWidget(new QPushButton("press", ui->centralWidget),2,2);
    ui->centralWidget->setLayout(hLayout);

    for (auto t : list) {
        cout << "value: " << t << endl;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
