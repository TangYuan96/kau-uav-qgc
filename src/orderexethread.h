#ifndef ORDEREXETHREAD_H
#define ORDEREXETHREAD_H

#include <QObject>
#include <QThread>
#include <string>
#include "globalv.h"

class orderExeThread: public QThread
{
    Q_OBJECT
public:
    explicit orderExeThread(QObject *parent = 0);
    virtual void run();


};

#endif // ORDEREXETHREAD_H
