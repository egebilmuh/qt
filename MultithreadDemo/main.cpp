#include <QCoreApplication>
#include "writerthread.h"
#include "readerthread.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Data<float>* data = new Data<float>();

    WriterThread writer(data);

    ReaderThread reader1(data);
    ReaderThread reader2(data);
    ReaderThread reader3(data);
    ReaderThread reader4(data);
    ReaderThread reader5(data);

    reader1.start();
    reader2.start();
    reader3.start();
    reader4.start();
    reader5.start();

    writer.start();


    return a.exec();
}
