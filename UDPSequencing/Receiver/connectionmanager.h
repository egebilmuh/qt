#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#include <QObject>

class ConnectionManager : public QObject
{
    Q_OBJECT
public:
    explicit ConnectionManager(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CONNECTIONMANAGER_H