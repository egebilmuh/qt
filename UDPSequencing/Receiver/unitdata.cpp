#include "unitdata.h"
UnitData::UnitData()
{
}

UnitData::~UnitData()
{
    qDeleteAll(dataMap.begin(), dataMap.end());
    dataMap.clear();
}
