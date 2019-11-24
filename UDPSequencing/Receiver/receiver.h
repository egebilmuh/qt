#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>
#include <QSharedPointer>
#include <queue>
#include "packet.h"
#include "communicationlibrary_global.h"

template<class T>
class MyCompare {
public:

  bool operator()( QSharedPointer<T> a, QSharedPointer<T> b) {
    return (*a) > (*b);
  }
};

typedef  std::priority_queue<QSharedPointer<Packet>, std::vector<QSharedPointer<Packet>>, MyCompare<Packet>/*std::greater<std::vector<Packet>::value_type>*/> buffer;

class Receiver : public QObject
{
    Q_OBJECT
public:
    Receiver();

private slots:
    void onReadUdp1();
    void onReadUdp1Backup();
    void onReadUdp2();
    void onReadUdp2Backup();
    void onReadUdp3();
    void onReadUdp3Backup();
    void processPendingDatagrams(QByteArray &datagram);

private:
    QUdpSocket udpSocket1;
    QUdpSocket udpSocket1Backup;
    QUdpSocket udpSocket2;
    QUdpSocket udpSocket2Backup;
    QUdpSocket udpSocket3;
    QUdpSocket udpSocket3Backup;
    QHostAddress groupAddress;
    uint waitPackSize;

    QMap<int,int> nextPacketNo;
    QMap<int, buffer> bufferMap;
};

#endif // RECEIVER_H
