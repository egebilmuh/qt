#include "senderthread.h"

SenderThread::SenderThread()
    : QThread ()
    , aborted (false)
    , counter1 (0)
    , counter2 (5)
{
    packet1.id = 1;
    packet2.id = 2;
    packet3.id = 3;
}

SenderThread::~SenderThread()
{
    mutex.lock();
    aborted = true;
    mutex.unlock();

    wait();
}

void SenderThread::run()
{
    while (!aborted && counter1 < 20) {
        sendData();
        usleep(100000);
    }

    std::cout << "sender finished" << std::endl;
}

void SenderThread::sendData()
{
    if(counter1%5==0)
        counter2 = counter1+5;
    packet1.sequence = counter2;
    packet2.sequence = counter2;
    packet3.sequence = counter2;

    std::fill(packet1.data, packet1.data+dataSize, counter2+0);
    std::fill(packet2.data, packet2.data+dataSize, counter2+1);
    std::fill(packet3.data, packet3.data+dataSize, counter2+2);

    emit sendData1(packet1);
    emit sendData2(packet2);
    emit sendData3(packet3);


    emit sendData1(packet1);
    emit sendData2(packet2);
    emit sendData3(packet3);

    counter1++;
    counter2--;
}
