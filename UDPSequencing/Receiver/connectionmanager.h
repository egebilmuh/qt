#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#include <QObject>
#include <QSharedPointer>
#include "udpreceiver.h"
#include "dataqueue.h"
#include "unitdata.h"

const uint DEFAULT_WAIT_COUNT = 100;
const QString DEFAULT_GROUP_ADR = "239.255.43.21";

class ConnectionManager : public QObject
{
    Q_OBJECT
public:
    explicit ConnectionManager(UnitData* datas, QObject *parent = nullptr);

public slots:
    void orderedU1DataReceived(QSharedPointer<Packet> packet);
    void orderedU2DataReceived(QSharedPointer<Packet> packet);
    void orderedU3DataReceived(QSharedPointer<Packet> packet);


private:
    QMap<int, UdpReceiver*> units;
    UnitData* datas;
};

#endif // CONNECTIONMANAGER_H
