#ifndef STATESENDTHREAD_H
#define STATESENDTHREAD_H

#include <QObject>
#include <QThread>
#include <string>
#include "globalv.h"

class stateSendThread : public QThread
{
    Q_OBJECT
public:
    explicit stateSendThread(QObject *parent = 0);



    virtual void run();

signals:
    void sendMsg(QString);
};

#endif // STATESENDTHREAD_H
