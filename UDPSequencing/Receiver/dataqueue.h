#ifndef DATA_H
#define DATA_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QMutexLocker>
#include <QDebug>

#include <cstring>


template<class T>
class Data
{
public:
    explicit Data(): written (false){}

    void writeData(T *data)
    {
        QMutexLocker locker(&dataMutex);
        std::memcpy(this->data, data, 1000* sizeof(T));
        written = true;
        dataWaitCond.wakeAll();
    }

    T* readData()
    {
        QMutexLocker locker(&dataMutex);

        if (!written) {
            qDebug() << "WaitingThreadId : " << QThread::currentThreadId();
            dataWaitCond.wait(&dataMutex);
            qDebug() << "Wait point passed : " << QThread::currentThreadId();
        }

        qDebug() << "ReadThreadId : " << QThread::currentThreadId();
        written = false;
        return data;
    }

private:
    T data[1000];
    QMutex dataMutex;
    QWaitCondition dataWaitCond;
    bool written;
};

#endif // DATA_H
