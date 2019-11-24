#include "receiverthread.h"

ReceiverThread::ReceiverThread()
    :aborted(false)
    , nextPacket(0)
{

}

ReceiverThread::~ReceiverThread()
{
    mutex.lock();
    aborted = true;
    mutex.unlock();
    wait();
}

void ReceiverThread::onData1Received(Packet p)
{
    buffer1.push(p);
}

void ReceiverThread::onData2Received(Packet p)
{
    buffer2.push(p);
}

void ReceiverThread::onData3Received(Packet p)
{
    buffer3.push(p);
}

void ReceiverThread::run()
{
    uint wait = 5*2;
    while(!aborted)
    {
        if (buffer1.size() > wait)
        {
            //wait = 0;
            std::cout << "buffer1: ";
            if(nextPacket <= buffer1.top().sequence)
            {
                std::cout << buffer1.top() << " size: " << buffer1.size() << std::endl;
                nextPacket = buffer1.top().sequence+1;
            }
            else {
                std::cout << "wrong packet: " << buffer1.top().sequence << std::endl;
            }
            buffer1.pop();
        }
        else {
            std::cout << "buffer1 emty" << std::endl;
        }

//        if (!buffer2.empty())
//        {
//            std::cout << "buffer2: ";
//            std::cout << buffer2.top() << " size: " << buffer2.size() << std::endl;
//            buffer2.pop();
//        }
//        else {
//            std::cout << "buffer2 emty" << std::endl;
//        }

//        if (!buffer3.empty())
//        {
//            std::cout << "buffer3: ";
//            std::cout << buffer3.top() << " size: " << buffer3.size() << std::endl;
//            buffer3.pop();
//        }
//        else {
//            std::cout << "buffer3 emty" << std::endl;
//        }

        //usleep(100000);
    }
}
