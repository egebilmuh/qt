#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include <QThread>
#include <QMutex>
#include <QElapsedTimer>
#include "unitdata.h"

const int UNIT_COUNT = 3;

class PreProcessor : public QThread
{
public:
    PreProcessor(UnitData* data);
    void start();
    void stop();
    bool isRunning();
protected:
    void run();
private:
    bool running;
    QMutex mutex;
    uint packCounter;
    UnitData* datas;

    ushort findSmallestPacketSeq(bool &ok);
    void fillAlgorithmData(QSharedPointer<floatData> algData);
};

#endif // PREPROCESSOR_H
