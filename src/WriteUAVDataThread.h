#ifndef WRITEUAVDATATHREAD_H
#define WRITEUAVDATATHREAD_H

#include <QObject>
#include <QThread>
#include "vehicleinfo.h"
#include "MultiVehicleManager.h"
#include "QGCApplication.h"
#include <string>

class WriteUAVDataThread : public QThread
{
    Q_OBJECT
public:
    explicit WriteUAVDataThread(QObject *parent = 0);
    virtual void run();

    MultiVehicleManager* getMultiVehicleManager() {myMultiVehicleManager;}

    // how to make these values are only one in global program ????
    MultiVehicleManager*  myMultiVehicleManager;
    Vehicle* myActiveVehicle;
    QmlObjectListModel* myVehicles;
    QmlObjectListModel CommandInfoList;


};

#endif // WRITEUAVDATATHREAD_H
