#include <QCoreApplication>
#include "spmanager.h"
#include <QDebug>


void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QFile outFile("log.txt");
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&outFile);
    ts << msg << endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile outFile("log.txt");
    outFile.open(QIODevice::WriteOnly | QIODevice::Truncate);
    outFile.close();

    qInstallMessageHandler(myMessageOutput);

    SPManager r;

    return a.exec();
}
