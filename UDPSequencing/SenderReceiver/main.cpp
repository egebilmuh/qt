#include <QCoreApplication>
#include "senderthread.h"
#include "receiverthread.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qRegisterMetaType<Packet>();


    ReceiverThread receiver;
    SenderThread sender;

    QObject::connect (&sender, &SenderThread::sendData1, &receiver, &ReceiverThread::onData1Received, Qt::QueuedConnection);
    QObject::connect (&sender, &SenderThread::sendData2, &receiver, &ReceiverThread::onData2Received, Qt::QueuedConnection);
    QObject::connect (&sender, &SenderThread::sendData3, &receiver, &ReceiverThread::onData3Received ,Qt::QueuedConnection);

    receiver.start();
    sender.start();

    return a.exec();
}
