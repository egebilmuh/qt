#include "sender.h"
#include <QDataStream>
#include <iostream>
#include <QElapsedTimer>

using namespace std;
Sender::Sender()
    : groupAddress(QStringLiteral("239.255.43.21"))
    , counter1 (0)
    , counter2 (5)
{
    connect(&timer, &QTimer::timeout, this, &Sender::sendData);
    timer.setTimerType(Qt::PreciseTimer);
    timer.start(2);
    cout << "constructor" << endl;
    packet1.id = 1;
    packet2.id = 2;
    packet3.id = 3;
}

void Sender::start()
{
    QMutexLocker locker(&mutex);
    running = true;
    QThread::start();
}

void Sender::stop()
{
    QMutexLocker locker(&mutex);
    running = false;
    wait();
}

bool Sender::isRunning()
{
    QMutexLocker locker(&mutex);
    return running;
}

void Sender::run()
{
    QElapsedTimer t;
    while (isRunning())
    {
        t.start();
        sendData();
        //while (t.nsecsElapsed() < 2000000);
        usleep(1000);
    }
}

void Sender::sendData()
{

    //if(counter1%5==0)
       // counter2 = counter1+5;
    packet1.sequence = counter1;
    packet2.sequence = counter1;
    packet3.sequence = counter1;

    std::fill(packet1.data, packet1.data+dataSize, (float)(counter1*3 + 1));
    std::fill(packet2.data, packet2.data+dataSize, (float)(counter1*3 + 2));
    std::fill(packet3.data, packet3.data+dataSize, (float)(counter1*3 + 3));

    QByteArray datagram1;
    QDataStream stream1(&datagram1, QIODevice::ReadWrite);

    stream1 << packet1;
    //cout << packet1 << endl;
//    uint writtenBytes;
//    writtenBytes = udpSocket.writeDatagram(datagram1, groupAddress, 45200);
//    cout << "Bytes written1: " << writtenBytes;
//    writtenBytes = udpSocket.writeDatagram(datagram1, groupAddress, 45201);
//    cout << "Bytes written2: " << writtenBytes;
    writeData(datagram1,45200);
    writeData(datagram1,45201);


    QByteArray datagram2;
    QDataStream stream2(&datagram2, QIODevice::ReadWrite);
    stream2 << packet2;
    //cout << packet2 << endl;

//    writtenBytes = udpSocket.writeDatagram(datagram2, groupAddress, 45202);
//    cout << "Bytes written3: " << writtenBytes;
//    writtenBytes = udpSocket.writeDatagram(datagram2, groupAddress, 45203);
//    cout << "Bytes written4: " << writtenBytes;
    writeData(datagram2,45202);
    writeData(datagram2,45203);

    QByteArray datagram3;
    QDataStream stream3(&datagram3, QIODevice::ReadWrite);
    stream3 << packet3;
    //cout << packet3 << endl;

//    writtenBytes = udpSocket.writeDatagram(datagram3, groupAddress, 45204);
//    cout << "Bytes written5: " << writtenBytes;
//    writtenBytes = udpSocket.writeDatagram(datagram3, groupAddress, 45205);
//    cout << "Bytes written6: " << writtenBytes;
    writeData(datagram3,45204);
    writeData(datagram3,45205);


    incrementCounter();
    counter2--;
    //qDebug() << "sending";
}

void Sender::incrementCounter()
{
    counter1 = (counter1+1) % powerOf2(serialbits);
}

void Sender::writeData(QByteArray &data, ushort port)
{
    uint writtenBytes;
    writtenBytes = udpSocket.writeDatagram(data, groupAddress, port);
    if(writtenBytes != 24584)
        cout << "Bytes written: " << writtenBytes << endl;
}
