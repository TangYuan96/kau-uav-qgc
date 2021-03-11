#ifndef READUAVDATATHREAD_H
#define READUAVDATATHREAD_H

#include <QObject>
#include <QThread>
#include "vehicleinfo.h"
#include "MultiVehicleManager.h"
#include "QGCApplication.h"
#include <string>

class ReadUAVDataThread : public QThread
{
    Q_OBJECT
public:
    explicit ReadUAVDataThread(QObject *parent = 0);

    virtual void run();

    MultiVehicleManager* getMultiVehicleManager() {myMultiVehicleManager;}

    // how to make these values are only one in global program ????
    MultiVehicleManager*  myMultiVehicleManager;
    Vehicle* myActiveVehicle;
    QmlObjectListModel* myVehicles;

    //QmlObjectListModel VehicleInfoList;
};

#endif // READUAVDATATHREAD_H
