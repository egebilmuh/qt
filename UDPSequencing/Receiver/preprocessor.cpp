#include "preprocessor.h"
#include <QMutexLocker>
#include <QtDebug>
#include <iostream>

using namespace std;
PreProcessor::PreProcessor(UnitData* unitData)
    :running(false)
    , packCounter (1)
    , datas (unitData)
{

}

void PreProcessor::run()
{
    QElapsedTimer t;
    int counter = 0;
    while (isRunning()) {

        t.start();
        QSharedPointer<floatData> algData(new floatData);
        std::fill(algData->data, algData->data+dataSize*3, 0.0f);
        static bool firstRun = true;
        if((datas->dataMap[1]->queueSize() > 20 && datas->dataMap[2]->queueSize() > 20 && datas->dataMap[3]->queueSize() > 20) || !firstRun)
        {
            fillAlgorithmData(algData);
            firstRun = false;
        }
        //        else if (!firstRun && (datas->dataMap[1]->queueSize() == 0 || datas->dataMap[2]->queueSize() == 0 || datas->dataMap[3]->queueSize() == 0)){
        //            cout << "buffer is zero!" << endl;
        //            firstRun = true;
        //        }
        else {
            // cout << "BUFFER SIZE < 20" << endl;
            //cout << "queue size: " << datas->dataMap[1]->queueSize() << endl ;
        }

        counter++;
        /*if (counter == 1520)*/ {
            counter = 0;
            qDebug() << "queue " << 1 << " size: " << datas->dataMap.value(1)->queueSize();
            qDebug() << "queue " << 2 << " size: " << datas->dataMap.value(2)->queueSize();
            qDebug() << "queue " << 3 << " size: " << datas->dataMap.value(3)->queueSize();
            qDebug() << "algdata first three: " << algData->data[0] << " " << algData->data[1] << " " << algData->data[2];

        }

        while (t.nsecsElapsed() < 1600000);
        qDebug() << t.nsecsElapsed() << endl;
    }
}

ushort PreProcessor::findSmallestPacketSeq(bool &ok)
{
    uint smallest = 0;
    ok = true;

    QSharedPointer<Packet> packet1 = datas->dataMap.value(1)->head();
    QSharedPointer<Packet> packet2 = datas->dataMap.value(2)->head();
    QSharedPointer<Packet> packet3 = datas->dataMap.value(3)->head();

    if(packet1.isNull() && packet2.isNull() && packet3.isNull())
    {
        ok = false;
        return 0;
    }

    if (packet1.isNull()) {
        if(!packet2.isNull())
            smallest = packet2->sequence;
        else {
            return packet3->sequence;
        }
    }
    else if(packet2.isNull())
    {
        if(!packet1.isNull())
            smallest = packet1->sequence;
        else {
            return packet3->sequence;
        }
    }
    else {
        if(isSmaller(packet1->sequence, packet2->sequence))
        {
            smallest = packet1->sequence;
        }
        else {
            smallest = packet2->sequence;
        }
    }

    if (packet3.isNull()) {
        return smallest;
    }
    else {
        if(isSmaller(smallest, packet3->sequence))
        {
            return smallest;
        }
        else {
             return packet3->sequence;
        }
    }
}

void PreProcessor::fillAlgorithmData(QSharedPointer<floatData> algData)
{

    //QSharedPointer<float> algDat = QSharedPointer<float>(new float[1843200]);
    //new float[18432];
    bool ok;
    uint smallestSeq = findSmallestPacketSeq(ok);

    for (int i = 1; i <=UNIT_COUNT;++i) {

        QSharedPointer<Packet> packet = datas->dataMap.value(i)->head();

        if (packet.isNull()) {
            //cout << "packet is null" << endl;
            continue;
        }

        if (isEqual(smallestSeq,packet->sequence)) {

            for (int j = 0; j < dataSize; j++) {
                algData->data[j*3+(i-1)] = packet->data[j];
            }

            datas->dataMap.value(i)->dequeDataOrWait();
        }
        else {
           // cout << "sequence number of " << i << " is greater than expected. " << "smallest: " << smallestSeq << " seq: " << datas->dataMap.value(i)->head()->sequence  << " data: " << datas->dataMap.value(i)->head()->data[0] <<  endl;
            //            cout << "queue " << 1 << " size: " << datas->dataMap.value(1)->queueSize() << endl;
            //            cout << "queue " << 2 << " size: " << datas->dataMap.value(2)->queueSize() << endl;
            //            cout << "queue " << 3 << " size: " << datas->dataMap.value(3)->queueSize() << endl;

            //            int m = datas->dataMap.value(i)->queueSize();
            //            for (int k = 0; k < m;++k) {

            //                cout << datas->dataMap.value(i)->dequeDataOrWait()->data[0] << endl;
            //            }

            //            int a = 0;
        }
    }
}

void PreProcessor::start()
{
    QMutexLocker locker(&mutex);
    running = true;
    QThread::start();
}

void PreProcessor::stop()
{
    QMutexLocker locker(&mutex);
    running = false;
    wait();
}

bool PreProcessor::isRunning()
{
    QMutexLocker locker(&mutex);
    return running;
}
