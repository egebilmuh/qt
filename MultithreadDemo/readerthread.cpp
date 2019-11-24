#include "readerthread.h"
#include <QMutexLocker>
#include <QtDebug>

ReaderThread::ReaderThread(Data<float> *data)
    :running (false)
    , data (data)
{

}

void ReaderThread::start()
{
    QMutexLocker locker(&mutex);
    running = true;
    QThread::start();
}

void ReaderThread::stop()
{
    QMutexLocker locker(&mutex);
    running = false;
}

bool ReaderThread::isRunning()
{
    QMutexLocker locker(&mutex);
    return running;
}

void ReaderThread::run()
{
    while (isRunning())
    {
        data->readData();
        qDebug() << "Data read thread id*: " << QThread::currentThreadId();
    }

}
