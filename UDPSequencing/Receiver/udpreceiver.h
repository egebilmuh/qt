#ifndef UDPRECEIVER_H
#define UDPRECEIVER_H

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

typedef  std::priority_queue<QSharedPointer<Packet>, std::vector<QSharedPointer<Packet>>, MyCompare<Packet>/*std::greater<std::vector<Packet>::value_type>*/> UdpBuffer;


class UdpReceiver : public QObject
{
    Q_OBJECT

public:
    UdpReceiver(QString multicastAddress, ushort port, ushort portBackup, uint waitCount);

private slots:
    void onReadUdp();
    void onReadUdpBackup();
signals:
    void dataReady(QSharedPointer<Packet>);
private:
    QUdpSocket udpSocket;
    QUdpSocket udpSocketBackup;
    uchar nextPacketNo;
    UdpBuffer buffer;
    QHostAddress groupAddress;
    uint waitPackSize;

    void processPendingDatagrams(QByteArray &datagram);
};

#endif // UDPRECEIVER_H
