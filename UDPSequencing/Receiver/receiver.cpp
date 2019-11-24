#include "receiver.h"
#include <QDataStream>
#include <iostream>

using namespace std;
Receiver::Receiver()
    : QObject ()
    , groupAddress(QStringLiteral("239.255.43.21"))
    , waitPackSize (20)
{
    udpSocket1.bind(QHostAddress::AnyIPv4, 45200, QUdpSocket::ShareAddress);
    udpSocket1Backup.bind(QHostAddress::AnyIPv4, 45201, QUdpSocket::ShareAddress);
    udpSocket2.bind(QHostAddress::AnyIPv4, 45202, QUdpSocket::ShareAddress);
    udpSocket2Backup.bind(QHostAddress::AnyIPv4, 45203, QUdpSocket::ShareAddress);
    udpSocket3.bind(QHostAddress::AnyIPv4, 45204, QUdpSocket::ShareAddress);
    udpSocket3Backup.bind(QHostAddress::AnyIPv4, 45205, QUdpSocket::ShareAddress);

    udpSocket1.joinMulticastGroup(groupAddress);
    udpSocket1Backup.joinMulticastGroup(groupAddress);
    udpSocket2.joinMulticastGroup(groupAddress);
    udpSocket2Backup.joinMulticastGroup(groupAddress);
    udpSocket3.joinMulticastGroup(groupAddress);
    udpSocket3Backup.joinMulticastGroup(groupAddress);

    connect(&udpSocket1, &QUdpSocket::readyRead, this, &Receiver::onReadUdp1);
    connect(&udpSocket1Backup, &QUdpSocket::readyRead, this, &Receiver::onReadUdp1Backup);
    connect(&udpSocket2, &QUdpSocket::readyRead, this, &Receiver::onReadUdp2);
    connect(&udpSocket2Backup, &QUdpSocket::readyRead, this, &Receiver::onReadUdp2Backup);
    connect(&udpSocket3, &QUdpSocket::readyRead, this, &Receiver::onReadUdp3);
    connect(&udpSocket3Backup, &QUdpSocket::readyRead, this, &Receiver::onReadUdp3Backup);
}

void Receiver::onReadUdp1()
{
    QByteArray datagram;

    // using QUdpSocket::readDatagram (API since Qt 4)
    while (udpSocket1.hasPendingDatagrams()) {
        datagram.resize(int(udpSocket1.pendingDatagramSize()));
        udpSocket1.readDatagram(datagram.data(), datagram.size());
        processPendingDatagrams(datagram);
    }
}

void Receiver::onReadUdp1Backup()
{
    QByteArray datagram;

    while (udpSocket1Backup.hasPendingDatagrams()) {
        datagram.resize(int(udpSocket1Backup.pendingDatagramSize()));
        udpSocket1Backup.readDatagram(datagram.data(), datagram.size());
        processPendingDatagrams(datagram);
    }
}

void Receiver::onReadUdp2()
{
    QByteArray datagram;

    while (udpSocket2.hasPendingDatagrams()) {
        datagram.resize(int(udpSocket2.pendingDatagramSize()));
        udpSocket2.readDatagram(datagram.data(), datagram.size());
        processPendingDatagrams(datagram);
    }
}

void Receiver::onReadUdp2Backup()
{
    QByteArray datagram;

    while (udpSocket2Backup.hasPendingDatagrams()) {
        datagram.resize(int(udpSocket2Backup.pendingDatagramSize()));
        udpSocket2Backup.readDatagram(datagram.data(), datagram.size());
        processPendingDatagrams(datagram);
    }
}

void Receiver::onReadUdp3()
{
    QByteArray datagram;

    while (udpSocket3.hasPendingDatagrams()) {
        datagram.resize(int(udpSocket3.pendingDatagramSize()));
        udpSocket3.readDatagram(datagram.data(), datagram.size());
        processPendingDatagrams(datagram);
    }
}

void Receiver::onReadUdp3Backup()
{
    QByteArray datagram;

    while (udpSocket3Backup.hasPendingDatagrams()) {
        datagram.resize(int(udpSocket3Backup.pendingDatagramSize()));
        udpSocket3Backup.readDatagram(datagram.data(), datagram.size());
        processPendingDatagrams(datagram);
    }
}

void Receiver::processPendingDatagrams(QByteArray &datagram)
{
    QDataStream stream(datagram);

    QSharedPointer<Packet> pack = QSharedPointer<Packet>(new Packet);

    stream >> *pack;

    ushort unitId = pack->id;

    bufferMap[unitId].push(pack);
    if (bufferMap.value(unitId).size() > waitPackSize)
    {
        std::cout << "buffer" << unitId<< ":";
        if(isEquealOrGreater(bufferMap.value(unitId).top()->sequence, nextPacketNo.value(unitId,0)))
        {
            std::cout << *bufferMap.value(unitId).top() << " size: " << bufferMap.value(unitId).size() << std::endl;
            nextPacketNo[unitId] = bufferMap.value(unitId).top()->sequence+1%powerOf2(serialbits);
        }
        else {
            std::cout << "wrong packet: " << bufferMap.value(unitId).top()->sequence << std::endl;
        }
        bufferMap[unitId].pop();
    }
    else {
        std::cout << "buffer " << unitId << " is not enough size: " << bufferMap.value(unitId).size() << std::endl;
    }
}
