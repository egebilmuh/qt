#ifndef SPMANAGER_H
#define SPMANAGER_H

#include <QObject>

class SPManager : public QObject
{
    Q_OBJECT
public:
    explicit SPManager(QObject *parent = nullptr);

signals:

public slots:
};

#endif // SPMANAGER_H