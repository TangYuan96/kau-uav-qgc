#include "WriteUAVDataThread.h"
#include <QDebug>
#include <QVariantList>
#include <QAbstractListModel>
#include <QThread>
#include <usedebug.h>
#include <string>
#include <QtCore/qstring.h>
using namespace std;

#include "QGCApplication.h"
#include "PX4FirmwarePlugin.h"
#include "PlanMasterController.h"
#include "MissionController.h"
#include "Vehicle.h"

WriteUAVDataThread::WriteUAVDataThread(QObject *parent) : QThread(parent)
{
  qDebug()<<"WriteUAVDataThread:"<<QThread::currentThreadId();
}


/*
 * MAV_CMD_NAV_TAKEOFF=22
 * MAV_CMD_NAV_LAND=21
 * MAV_CMD_NAV_LAND_LOCAL=23,
 * MAV_CMD_NAV_TAKEOFF_LOCAL=24,
 * MAV_CMD_DO_REPOSITION=192, /* Reposition the vehicle to a specific WGS84 global position
 */
/*
    vehicle->flightMode()
    "Takeoff" --guidedModeTakeoff
    "Hold" -- pause
    "Return" -- rtl
    "Land"  -- land
    "Mission"  -- openPlan

*/
bool handleCommand(QString command, Vehicle* vehicle){

    bool successFlag = false;

    // takeoff
    if(command=="takeoff"){
        vehicle->guidedModeTakeoff(20);
        QThread::sleep(3);
        QString flightMode = vehicle->flightMode();
        qDebug()<<"takeoff!!!!!    flightMode : "<<flightMode;
        if(flightMode== "Takeoff"){
             successFlag= true;
        }
    }
    // land
    else if(command == "land"){
          vehicle->guidedModeLand();
          QThread::sleep(3);
          QString flightMode = vehicle->flightMode();
          qDebug()<<"land!!!!!    flightMode : "<<flightMode;
          if(flightMode== "Land") {
              successFlag= true;
          }
    }
    // RTL
    else if(command=="RTL"){
          vehicle->guidedModeRTL();
          QThread::sleep(5);
          QString flightMode = vehicle->flightMode();
          qDebug()<<"rtl!!!!!    flightMode : "<<flightMode;
          if(flightMode == "Return") {
              successFlag= true;
          }
    }
    // openPlan
    else if(command=="openPlan"){
        vehicle->openPlan("/home/xu/Desktop/test2.plan");
        QThread::sleep(5);
        QString flightMode = vehicle->flightMode();
        qDebug()<<"openPlan!!!!!    flightMode : "<<flightMode;
        if(flightMode == "Mission") {
            successFlag= true;
        }
    }
    // pause or changeAltitude
    else if(command=="hold" || command.contains("changeAltitude")){
        QThread::sleep(5);
        qDebug()<<"hold or changeAltitude  ";
        if(command=="hold"){
            vehicle->pauseVehicle();
            Vehicle::MavCommandInfo mavCommand = vehicle->returnMavCommandQueue();
            int mavCommandNum = mavCommand.command;
            bool mavCommandSuccess = mavCommand.showError;
            bool mavCommandLastParam = qIsNaN(mavCommand.rgParam6)  ;   //isnan() doesn't work
            if(mavCommandNum == 192 && mavCommandLastParam && mavCommandSuccess){
                successFlag= true;
            }
        }
        else if(command.contains("changeAltitude")){
            int Altitude = command.split("+")[1].toInt();
            vehicle->guidedModeChangeAltitude(Altitude);
            Vehicle::MavCommandInfo mavCommand = vehicle->returnMavCommandQueue();
            int mavCommandNum = mavCommand.command;
            bool mavCommandSuccess = mavCommand.showError;
            bool mavCommandLastParam = qIsNaN(mavCommand.rgParam6);
            if(mavCommandNum == 192 && !mavCommandLastParam && mavCommandSuccess){
                successFlag= true;
            }
        }
  }
     return successFlag;
}

void WriteUAVDataThread::run()
{
    qDebug()<<"WriteThread ---- myThread run() start to execute";
    qDebug()<<"WriteThread ---- current thread ID:"<<QThread::currentThreadId()<<'\n';
        //emit myThreadSignal(count);

    int a = 1;

    for (a = 1;a<3;a++)
    {
        QThread::sleep(5);
        qDebug()<<"time:%d"<<a;
    }
     myMultiVehicleManager =  qgcApp()->toolbox()->multiVehicleManager();

    // vehicles that have been connected
     myVehicles =  qgcApp()->toolbox()->multiVehicleManager()->vehicles();

    QStringList message = {
                           "takeoff::0",
                           "changeAltitude+20::0",
                           "land::0",
                           "RTL::0",
                           "hold::0",
                           "openPlan::0"
                          };

    while(1)
    {
      QThread::sleep(3);
      int stringLen = message.count();
      if(stringLen > 0){
        if ( myMultiVehicleManager->activeVehicleAvailable())
            {
                qDebug()<<"activeVehicleAvailable()";

                // get current active Vehicle
                myActiveVehicle  =  myMultiVehicleManager->activeVehicle();
                qDebug()<<"myActiveVehicle"<<myActiveVehicle;


                QString flightMode = myActiveVehicle->flightMode();
                qDebug()<<"flightMode : "<<flightMode;


                // display vehicle in control in qgc
                myActiveVehicle->changeUnderControlValue(true);

                // handleCommand

                QStringList info = message[0].split("::");
                QString command = info[0];
                int vehicleId = info[1].toInt();

                bool commandSuccess =  handleCommand(command,myActiveVehicle);
                if(commandSuccess){
                    qDebug()<<"message--"<<message;
                    message.pop_front();
                }else{
                    // alert
                }
            }
        else
            {//now ,there is no active vehicle,wait next time
                qDebug()<<"activeVehicleUnavailable()";
                continue;
            }
      }

    }
        exec();
}
