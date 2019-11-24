#include "connectionmanager.h"

ConnectionManager::ConnectionManager(UnitData* unitDatas, QObject *parent)
    : QObject(parent)
    , datas (unitDatas)
{
    ushort port = 45200;

    for (int i = 0 ; i < 3; ++i) {
        UdpReceiver*  ur = new UdpReceiver(DEFAULT_GROUP_ADR, port+i*2, port+i*2+1, DEFAULT_WAIT_COUNT);
        units.insert(i+1, ur);
        datas->dataMap.insert(i+1, new DataQueue<Packet>());
    }
    connect(units.value(1), &UdpReceiver::dataReady, this, &ConnectionManager::orderedU1DataReceived);
    connect(units.value(2), &UdpReceiver::dataReady, this, &ConnectionManager::orderedU2DataReceived);
    connect(units.value(3), &UdpReceiver::dataReady, this, &ConnectionManager::orderedU3DataReceived);
}


void ConnectionManager::orderedU1DataReceived(QSharedPointer<Packet> packet)
{
    //std::cout << "paket 1: " << *packet << std::endl;
    datas->dataMap[packet->id]->enqueueData(packet);
}

void ConnectionManager::orderedU2DataReceived(QSharedPointer<Packet> packet)
{
    //std::cout << "paket 2: " << *packet << std::endl;
    //QMap<int, Data<Packet>*>::iterator it= datas->dataMap.find(packet->id);
    datas->dataMap[packet->id]->enqueueData(packet);

}

void ConnectionManager::orderedU3DataReceived(QSharedPointer<Packet> packet)
{
    //std::cout << "paket 3: " << *packet << std::endl;
    datas->dataMap[packet->id]->enqueueData(packet);
}
