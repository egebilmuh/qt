#ifndef READERTHREAD_H
#define READERTHREAD_H

#include <QThread>
#include <QMutex>
#include <data.h>

class ReaderThread : public QThread
{
public:
    ReaderThread(Data<float>* data);
    void start();
    void stop();
    bool isRunning();
    void run() override;
private:
    QMutex mutex;
    bool running;
    Data<float>* data;
};

#endif // READERTHREAD_H
