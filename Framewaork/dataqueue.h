#ifndef DATAQUEUE_H
#define DATAQUEUE_H
#include <QQueue>

template <class T>
class DataQueue
{
public:
    DataQueue(){}

private:
    QQueue<T>* dataQueue;
};

#endif // DATAQUEUE_H
