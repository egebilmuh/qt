#ifndef SENDER_H
#define SENDER_H
#include <QUdpSocket>
#include <QObject>
#include <QTimer>
#include "packet.h"
#include <QThread>
#include <QMutex>


class Sender : public QThread
{
    Q_OBJECT
public:
    Sender();
    void start();
    void stop();
    bool isRunning();
protected:
    void run();
private:
    bool running;
    QMutex mutex;

private slots:
    void sendData();


private:
    QUdpSocket udpSocket;
    QTimer timer;
    QHostAddress groupAddress;

    void incrementCounter();

    void writeData(QByteArray &data, ushort port);

    uchar counter1;
    uchar counter2;
    Packet packet1;
    Packet packet2;
    Packet packet3;
};

#endif // SENDER_H
