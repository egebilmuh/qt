#include "writerthread.h"
#include <QMutexLocker>
#include <QtDebug>


WriterThread::WriterThread(Data<float>* data)
    :running (false)
    , data (data)
{

}

void WriterThread::start()
{
    QMutexLocker locker(&mutex);
    running = true;
    QThread::start();
}

void WriterThread::stop()
{
    QMutexLocker locker(&mutex);
    running = false;
    wait();
}

bool WriterThread::isRunning()
{
    QMutexLocker locker(&mutex);
    return running;
}

void WriterThread::run()
{
    float datas[1000];
    while (isRunning())
    {
        data->writeData(datas);
        qDebug() << "data written";
        usleep(10000000);
    }
}
