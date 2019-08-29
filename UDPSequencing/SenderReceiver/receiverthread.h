#ifndef RECEIVERTHREAD_H
#define RECEIVERTHREAD_H

#include <QObject>
#include <QThread>
#include <QMutex>
#include <queue>
#include "packet.h"


class ReceiverThread : public QThread
{
public:
    ReceiverThread();
    ~ReceiverThread() override;

public slots:
    void onData1Received(Packet);
    void onData2Received(Packet);
    void onData3Received(Packet);

protected:
    void run() override;

private:
    bool aborted;
    QMutex mutex;

    uint nextPacket;
    std::priority_queue<Packet, std::vector<Packet>, std::greater<std::vector<Packet>::value_type>> buffer1;
    std::priority_queue<Packet, std::vector<Packet>, std::greater<std::vector<Packet>::value_type>> buffer2;
    std::priority_queue<Packet, std::vector<Packet>, std::greater<std::vector<Packet>::value_type>> buffer3;
};

#endif // RECEIVERTHREAD_H
