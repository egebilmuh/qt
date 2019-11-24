#include "udpreceiver.h"
#include <QDataStream>

UdpReceiver::UdpReceiver(QString multicastAddress, ushort port, ushort portBackup, uint waitCount)
    : QObject ()
    , nextPacketNo (0)
    , groupAddress(multicastAddress)
    , waitPackSize (waitCount)
{
    udpSocket.bind(QHostAddress::AnyIPv4, port, QUdpSocket::ShareAddress);
    udpSocketBackup.bind(QHostAddress::AnyIPv4, portBackup, QUdpSocket::ShareAddress);

    udpSocket.joinMulticastGroup(groupAddress);
    udpSocketBackup.joinMulticastGroup(groupAddress);

    connect(&udpSocket, &QUdpSocket::readyRead, this, &UdpReceiver::onReadUdp);
    connect(&udpSocketBackup, &QUdpSocket::readyRead, this, &UdpReceiver::onReadUdpBackup);
}

void UdpReceiver::onReadUdp()
{
    QByteArray datagram;

    // using QUdpSocket::readDatagram (API since Qt 4)
    while (udpSocket.hasPendingDatagrams()) {
        datagram.resize(int(udpSocket.pendingDatagramSize()));
        if(datagram.size() != 24584)
            qDebug() << "data size incorrect: " << datagram.size();
        udpSocket.readDatagram(datagram.data(), datagram.size());
        processPendingDatagrams(datagram);
    }
}

void UdpReceiver::onReadUdpBackup()
{
    QByteArray datagram;

    // using QUdpSocket::readDatagram (API since Qt 4)
    while (udpSocketBackup.hasPendingDatagrams()) {
        datagram.resize(int(udpSocketBackup.pendingDatagramSize()));
        if(datagram.size() != 24584)
            qDebug() << "data size incorrect: " << datagram.size();
        udpSocketBackup.readDatagram(datagram.data(), datagram.size());
        processPendingDatagrams(datagram);
    }
}

void UdpReceiver::processPendingDatagrams(QByteArray &datagram)
{
    QDataStream stream(datagram);

    QSharedPointer<Packet> pack = QSharedPointer<Packet>(new Packet);

    stream >> *pack;

    buffer.push(pack);
    if (buffer.size() > waitPackSize)
    {
        //std::cout << "buffer" << ":";
        static bool firstRun = true;
        //qDebug() << *buffer.top() << " size: " << buffer.size();

        if(isEquealOrGreater(buffer.top()->sequence, nextPacketNo) || firstRun)
        {
            if (isGreater(buffer.top()->sequence, nextPacketNo))
                qDebug() << "greater: " << buffer.top().data()[0];
            emit dataReady(buffer.top());
            nextPacketNo = (buffer.top()->sequence+1)%powerOf2(serialbits);
            firstRun = false;
        }
        else {
            //qDebug() << "wrong packet port(" << udpSocket.localPort() << "- expected: " << (int)nextPacketNo << " received: " << buffer.top()->sequence << " dat: " << buffer.top().data()[0];
        }
        buffer.pop();
    }
    else {
        //std::cout << "buffer is not enough size: " << buffer.size() << std::endl;
    }
}
