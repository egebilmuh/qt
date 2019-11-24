#include "printingdemo.h"
#include <windows.h>
#include <winspool.h>
#include <QDateTime>

using namespace std;

//static QWaitCondition waitCond;
//static QMutex qmutex;

void checkPrinter(bool &result)
{
    //    qDebug() << "running...";
    //    const int work = 5000;//1000 * 1000 * 400;
    //    for (int i = 0; i < work; i++) {
    //    }
    //    result = true;
    //    qDebug() << "finished";

    _sleep(10000);

    result = false;

    WCHAR wsPrinter[MAX_PATH] = { 0 };
    DWORD dwBufferSize = ARRAYSIZE(wsPrinter);
    if (GetDefaultPrinter(wsPrinter, &dwBufferSize))
    {
        HANDLE hPrinter = NULL;
        if (OpenPrinter(wsPrinter, &hPrinter, NULL))
        {
            DWORD cByteNeeded, nReturned, cByteUsed;
            PRINTER_INFO_2 *pPrinterInfo = NULL;
            if (!GetPrinter(hPrinter, 2, NULL, 0, &cByteNeeded))
            {
                if (GetLastError() != ERROR_INSUFFICIENT_BUFFER)
                {
                    result = false;
                    //waitCond.wakeAll();
                    return;
                }
                pPrinterInfo = (PRINTER_INFO_2 *)malloc(cByteNeeded);
                if (!(pPrinterInfo))
                {
                    result = false;
                    //waitCond.wakeAll();
                    return;
                }
                if (!GetPrinter(hPrinter, 2, (LPBYTE)pPrinterInfo, cByteNeeded, &cByteUsed))
                {
                    free(pPrinterInfo);
                    pPrinterInfo = NULL;
                    result = false;
                    //waitCond.wakeAll();
                    return;
                }
                else
                {
                    DWORD dwStatus = pPrinterInfo->Status;
                    if (dwStatus & PRINTER_STATUS_OFFLINE)
                    {
                        result = false;
                        //waitCond.wakeAll();
                    }
                    else {
                        result = true;
                        qDebug() << "check printer printer is online";
                        //waitCond.wakeAll();
                    }
                }
            }
            ClosePrinter(hPrinter);
        }
    }
}


PrintingDemo::PrintingDemo()
{
    result.append(false);
    timer.setInterval(100);
    timer.setSingleShot(true);
    timer.setTimerType(Qt::PreciseTimer);
    connect(&watcher, &QFutureWatcher<void>::finished, this, &PrintingDemo::onPrinterResultReady);
    connect(&timer, &QTimer::timeout, this, &PrintingDemo::onTimerTimerTimeout);
}

PrintingDemo::~PrintingDemo()
{

}

bool PrintingDemo::isPrinterAvailable()
{
    result[0] = false;
    if(!watcher.isRunning())
    {
        qDebug() << "start time: " << QTime::currentTime().toString("hh:mm::ss:zzz");
        timer.start();
        watcher.setFuture(QtConcurrent::map(result, &checkPrinter));
        eventLoop.exec();
//        QMutexLocker mlc(&qmutex);
//        qApp->processEvents();
//        waitCond.wait(&qmutex, 100);
//        qApp->processEvents();

        if(watcher.isRunning())
        {
            qDebug() << "cancel watcher";
            watcher.cancel();
        }
        qDebug() << "return isAvailable:" << result.at(0) << " : " << QTime::currentTime().toString("hh:mm::ss:zzz");;
    }
    else {
        qDebug() << "already running";
    }

    return result.at(0);
}

void PrintingDemo::onPrinterResultReady()
{
    if (watcher.isCanceled())
        qDebug() << "watcher canceled!";
    else
    {
        qDebug() << "check status returned : " << QTime::currentTime().toString("hh:mm::ss:zzz");
        if(eventLoop.isRunning())
        {
            qDebug() << "watcher finished stop event loop";
            eventLoop.quit();
        }
        else {
            qDebug() << "event loop is not running finished";
        }
    }

}

void PrintingDemo::onTimerTimerTimeout()
{
    qDebug() << "timeout time: " << QTime::currentTime().toString("hh:mm::ss:zzz");
    if (watcher.isRunning())
    {
        watcher.canceled();
        qDebug() << "watcher canceled by timer.";
    }
    else {
        qDebug() << "watcher is not running timer";
    }

    if(eventLoop.isRunning())
    {
        qDebug() << "timer stoping event loop";
        eventLoop.quit();
    }
    else
        qDebug() << "event loop is not running timer!";
}
