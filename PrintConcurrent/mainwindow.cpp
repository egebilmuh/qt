#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    static int count = 0;
    count++;
    bool res = pd.isPrinterAvailable();
    if(res)
        ui->statusbar->showMessage(QString("printer avaliable %1").arg(count));
    else
        ui->statusbar->showMessage(QString("printer not avaliable %1").arg(count));
}
