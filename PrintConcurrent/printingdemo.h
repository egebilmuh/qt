#ifndef PRINTINGDEMO_H
#define PRINTINGDEMO_H
#include <QtConcurrent>
#include <QTimer>
#include <QVector>
#include <QWaitCondition>


class PrintingDemo : public QObject
{
    Q_OBJECT
public:
    PrintingDemo();
    virtual ~PrintingDemo();
    bool isPrinterAvailable();
    QFutureWatcher<void> watcher;
    void onPrinterResultReady();
    void onTimerTimerTimeout();
    QTimer timer;
    QVector<bool> result;
    QEventLoop eventLoop;

    friend void checkPrinter(bool&result);

};

#endif // PRINTINGDEMO_H
