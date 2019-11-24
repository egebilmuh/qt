#ifndef WRITERTHREAD_H
#define WRITERTHREAD_H

#include <QThread>
#include <QMutex>
#include <data.h>


class WriterThread : public QThread
{
public:
    WriterThread(Data<float>* data);

    void start();
    void stop();
    bool isRunning();
    void run() override;


private:
    QMutex mutex;
    bool running;
    Data<float>* data;
};

#endif // WRITERTHREAD_H
