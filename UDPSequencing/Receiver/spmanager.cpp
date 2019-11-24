#include "spmanager.h"

SPManager::SPManager(QObject *parent) : QObject(parent)
{
    datas = new UnitData();
    conMan = new ConnectionManager(datas);
    preprocessor = new PreProcessor(datas);
    preprocessor->start();
}
