#include <QCoreApplication>
#include "sender.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Sender s;
    //s.start();

    return a.exec();
}
