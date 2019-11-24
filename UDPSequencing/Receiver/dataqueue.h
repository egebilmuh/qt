#ifndef DATA_H
#define DATA_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QMutexLocker>
#include <QDebug>
#include <QQueue>
#include <QSharedPointer>

#include <cstring>


template<class T>
class DataQueue
{
public:
    explicit DataQueue(): written (false){}

    void enqueueData(QSharedPointer<T> data)
    {
        QMutexLocker locker(&dataMutex);
        this->data.enqueue(data);
        //written = true;
        dataWaitCond.wakeAll();
    }

    QSharedPointer<T> dequeDataOrWait()
    {
        QMutexLocker locker(&dataMutex);

        if (data.size() < 2) {
            qDebug() << "WaitingThreadId : " << QThread::currentThreadId();
            dataWaitCond.wait(&dataMutex);

            //qDebug() << "Wait point passed : " << QThread::currentThreadId();
        }

        //qDebug() << "ReadThreadId : " << QThread::currentThreadId();
        //written = false;
        return data.dequeue();
    }

    const QSharedPointer<T> head()
    {
        QMutexLocker locker(&dataMutex);
        if (!data.isEmpty()) {
            return data.head();
        }
        else {
            return QSharedPointer<T>(nullptr);
        }
    }

    int queueSize()
    {
        QMutexLocker locker(&dataMutex);
            return data.size();
    }

private:
    QQueue<QSharedPointer<T>> data;
    QMutex dataMutex;
    QWaitCondition dataWaitCond;
    bool written;
};

#endif // DATA_H
