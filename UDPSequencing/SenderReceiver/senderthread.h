#ifndef SERNDERTHREAD_H
#define SERNDERTHREAD_H

#include <QObject>
#include <QThread>
#include <QMutex>
#include <QSharedPointer>

#include "packet.h"

template< class T>
void doDelete(T buf[]){
    delete [] buf;
}

class SenderThread : public QThread
{
    Q_OBJECT
public:
    SenderThread();
    ~SenderThread() override;

signals:
    void sendData1(Packet);
    void sendData2(Packet);
    void sendData3(Packet);

protected:
    void run() override;

private:

    bool aborted;
    QMutex mutex;

    uint counter1;
    uint counter2;
    Packet packet1;
    Packet packet2;
    Packet packet3;

    void sendData();
};

#endif // SERNDERTHREAD_H
