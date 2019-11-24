#ifndef SPMANAGER_H
#define SPMANAGER_H

#include <QObject>

#include "connectionmanager.h"
#include "preprocessor.h"
#include "unitdata.h"

class SPManager : public QObject
{
    Q_OBJECT
public:
    explicit SPManager(QObject *parent = nullptr);

signals:

public slots:

private:
    ConnectionManager *conMan;
    PreProcessor* preprocessor;
    UnitData* datas;
};

#endif // SPMANAGER_H
