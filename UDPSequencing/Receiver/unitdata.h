#ifndef UNITDATA_H
#define UNITDATA_H

#include <QObject>
#include "dataqueue.h"
#include "packet.h"

class UnitData
{
public:
    UnitData();
    ~UnitData();
    QMap<int, DataQueue<Packet>*> dataMap;
};

#endif // UNITDATA_H
