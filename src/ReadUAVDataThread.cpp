#include "ReadUAVDataThread.h"
#include <QDebug>
#include <QVariantList>
#include <QAbstractListModel>
#include <QThread>
#include <usedebug.h>
#include <string>
#include "globalv.h"
#include "json.hpp"
#include <QString>

ReadUAVDataThread::ReadUAVDataThread(QObject *parent) : QThread(parent)
{
  qDebug()<<"ReadUAVDataThread:"<<QThread::currentThreadId();
}




void saveValue(double* tempValue, Fact* value, char* valueName)
{
    bool convertOk = false;
    *tempValue = value->rawValue().toDouble(&convertOk);
    if (convertOk == false)
        {
            qdebug1("%s converError!",valueName);
        }
    else
        {
            qdebug3("temp->%s:%f",valueName, *tempValue) ;
        }
}




void saveAsVehicleInfo(Vehicle* vehicle1, VehicleInfo* temp)
{

    qDebug()<<"saveAsVehicleInfo";
    ////    VehicleInfo temp;
    bool convertOk = false;

    temp->id = vehicle1->id();
    qDebug()<< "temp->id:"<<temp->id;

    temp->active = vehicle1->active();
    qDebug()<< "temp->active:"<<temp->active;

    //temp->roll = vehicle1->roll()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->roll), vehicle1->roll(), "roll");

    //temp->pitch = vehicle1->pitch()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->pitch), vehicle1->pitch(), "pitch");

    //temp->heading = vehicle1->heading()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->heading), vehicle1->heading(), "heading");


    //temp->rollRate = vehicle1->rollRate()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->rollRate), vehicle1->rollRate(), "rollRate");


   // temp->pitchRate = vehicle1->pitchRate()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->pitchRate), vehicle1->pitchRate(), "pitchRate");

    //temp->yawRate = vehicle1->yawRate()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->yawRate), vehicle1->yawRate(), "yawRate");

    //temp->groundSpeed = vehicle1->groundSpeed()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->groundSpeed), vehicle1->groundSpeed(), "groundSpeed");

   // temp->airSpeed = vehicle1->airSpeed()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->airSpeed), vehicle1->airSpeed(), "airSpeed");

    //temp->climbRate = vehicle1->climbRate()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->climbRate), vehicle1->climbRate(), "climbRate");

   // temp->altitudeRelative = vehicle1->altitudeRelative()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->altitudeRelative), vehicle1->altitudeRelative(), "altitudeRelative");

    //temp->altitudeAMSL = vehicle1->altitudeAMSL()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->altitudeAMSL), vehicle1->altitudeAMSL(), "altitudeAMSL");

    //temp->flightDistance = vehicle1->flightDistance()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->flightDistance), vehicle1->flightDistance(), "flightDistance");

//    temp->flightTime = vehicle1->flightTime()->rawValue().toDouble(&convertOk);
//    if (convertOk == false)
//        {
//            qDebug()<< "flightTime converError!";
//        }

    //temp->distanceToHome = vehicle1->distanceToHome()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->distanceToHome), vehicle1->distanceToHome(), "distanceToHome");

    // the format of hobbs is not double
    // temp->hobbs = vehicle1->hobbs()->rawValue().toDouble(&convertOk);
    // saveValue(&(temp->hobbs), vehicle1->hobbs(), "hobbs");


    FactGroup* gpsTemp = vehicle1->gpsFactGroup();
    VehicleGPSFactGroup*  GPSGroupTemp = dynamic_cast<VehicleGPSFactGroup*>(gpsTemp);
   // temp->gps_lat  = GPSGroupTemp->lat()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->gps_lat), GPSGroupTemp->lat(), "gps_lat");

    //temp->gps_lon = GPSGroupTemp->lon()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->gps_lon), GPSGroupTemp->lon(), "gps_lon");

    //temp->gps_hdop = GPSGroupTemp->hdop()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->gps_hdop), GPSGroupTemp->hdop(), "gps_hdop");

    //temp->gps_vdop = GPSGroupTemp->vdop()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->gps_vdop), GPSGroupTemp->vdop(), "gps_vdop");

    //temp->gps_courseOverGround =GPSGroupTemp->courseOverGround()->rawValue().toDouble(&convertOk) ;
    saveValue(&(temp->gps_courseOverGround), GPSGroupTemp->courseOverGround(), "gps_courseOverGround");

    //temp->gps_count = GPSGroupTemp->count()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->gps_count), GPSGroupTemp->count(), "gps_count");

    //temp->gps_lock = GPSGroupTemp->lock()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->gps_lock), GPSGroupTemp->lock(), "gps_lock");


    FactGroup* battery1Temp = vehicle1->battery1FactGroup();
    VehicleBatteryFactGroup*  battery1GroupTemp = dynamic_cast<VehicleBatteryFactGroup*>(battery1Temp);
    //temp->battery1_percentRemaining =  battery1GroupTemp->percentRemaining()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->battery1_percentRemaining), battery1GroupTemp->percentRemaining(), "battery1_percentRemaining");

    //temp->battery1_mahConsumed =  battery1GroupTemp->mahConsumed()->rawValue().toDouble(&convertOk)  ;
    saveValue(&(temp->battery1_mahConsumed), battery1GroupTemp->mahConsumed(), "battery1_mahConsumed");

    //temp->battery1_current =  battery1GroupTemp->current()->rawValue().toDouble(&convertOk)  ;
    saveValue(&(temp->battery1_current), battery1GroupTemp->current(), "battery1_current");

    //temp->battery1_temperature =  battery1GroupTemp->temperature()->rawValue().toDouble(&convertOk)    ;
    saveValue(&(temp->battery1_temperature), battery1GroupTemp->temperature(), "battery1_temperature");

    //temp->battery1_cellCount =  battery1GroupTemp->cellCount()->rawValue().toDouble(&convertOk)    ;
    saveValue(&(temp->battery1_cellCount), battery1GroupTemp->cellCount(), "battery1_cellCount");

    //temp->battery1_instantPower =  battery1GroupTemp->instantPower()->rawValue().toDouble(&convertOk)    ;
    saveValue(&(temp->battery1_instantPower), battery1GroupTemp->instantPower(), "battery1_instantPower");

    //temp->battery1_timeRemaining =  battery1GroupTemp->timeRemaining()->rawValue().toDouble(&convertOk)    ;
    saveValue(&(temp->battery1_timeRemaining), battery1GroupTemp->instantPower(), "battery1_timeRemaining");

    //temp->battery1_chargeState = battery1GroupTemp->chargeState()->rawValue().toDouble(&convertOk)    ;
    saveValue(&(temp->battery1_chargeState), battery1GroupTemp->chargeState(), "battery1_chargeState");



    FactGroup* battery2Temp = vehicle1->battery2FactGroup();
    VehicleBatteryFactGroup*  battery2GroupTemp = dynamic_cast<VehicleBatteryFactGroup*>(battery2Temp);
    //temp->battery2_percentRemaining =  battery2GroupTemp->percentRemaining()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->battery2_percentRemaining), battery2GroupTemp->percentRemaining(), "battery2_percentRemaining");

    //temp->battery2_mahConsumed =  battery2GroupTemp->mahConsumed()->rawValue().toDouble(&convertOk)  ;
    saveValue(&(temp->battery2_mahConsumed), battery2GroupTemp->mahConsumed(), "battery2_mahConsumed");

   // temp->battery2_current =  battery2GroupTemp->current()->rawValue().toDouble(&convertOk)  ;
    saveValue(&(temp->battery2_current), battery2GroupTemp->current(), "battery2_current");

    //temp->battery2_temperature =  battery2GroupTemp->temperature()->rawValue().toDouble(&convertOk)    ;
    saveValue(&(temp->battery2_temperature), battery2GroupTemp->temperature(), "battery2_temperature");

    //temp->battery2_cellCount =  battery2GroupTemp->cellCount()->rawValue().toDouble(&convertOk)    ;
    saveValue(&(temp->battery2_cellCount), battery2GroupTemp->cellCount(), "battery2_cellCount");

    //temp->battery2_instantPower =  battery2GroupTemp->instantPower()->rawValue().toDouble(&convertOk)    ;
    saveValue(&(temp->battery2_instantPower), battery2GroupTemp->instantPower(), "battery2_instantPower");

    //temp->battery2_timeRemaining =  battery2GroupTemp->timeRemaining()->rawValue().toDouble(&convertOk)    ;
    saveValue(&(temp->battery2_timeRemaining), battery2GroupTemp->instantPower(), "battery2_timeRemaining");

    //temp->battery2_chargeState = battery2GroupTemp->chargeState()->rawValue().toDouble(&convertOk)    ;
    saveValue(&(temp->battery2_chargeState), battery2GroupTemp->chargeState(), "battery2_chargeState");


    //wind parameter
    FactGroup* windTemp = vehicle1->windFactGroup();
    VehicleWindFactGroup*  windGroupTemp = dynamic_cast<VehicleWindFactGroup*>(windTemp);
    //temp->wind_direction =  windGroupTemp->direction()->rawValue().toDouble(&convertOk)     ;
    saveValue(&(temp->wind_direction), windGroupTemp->direction(), "wind_direction");

    //temp->wind_speed =  windGroupTemp->speed()->rawValue().toDouble(&convertOk)      ;
    saveValue(&(temp->wind_speed), windGroupTemp->speed(), "wind_speed");

    //temp->wind_verticalSpeed  =  windGroupTemp->verticalSpeed()->rawValue().toDouble(&convertOk)      ;
    saveValue(&(temp->wind_verticalSpeed),  windGroupTemp->verticalSpeed(), "wind_verticalSpeed");



    //vibration parameter
    FactGroup* vibrationTemp = vehicle1->vibrationFactGroup();
    VehicleVibrationFactGroup*  vibrationGroupTemp = dynamic_cast<VehicleVibrationFactGroup*>(vibrationTemp);
    //temp->vibration_xAxis  =   vibrationGroupTemp->xAxis()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->vibration_xAxis),  vibrationGroupTemp->xAxis(), "vibration_xAxis");

    //temp->vibration_yAxis  =  vibrationGroupTemp->yAxis()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->vibration_yAxis),  vibrationGroupTemp->yAxis(), "vibration_yAxis");

    //temp->vibration_zAxis  = vibrationGroupTemp->zAxis()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->vibration_zAxis),  vibrationGroupTemp->zAxis(), "vibration_zAxis");

   // temp->vibration_clipCount1  =  vibrationGroupTemp->clipCount1()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->vibration_clipCount1),  vibrationGroupTemp->clipCount1(), "vibration_clipCount1");

    //temp->vibration_clipCount2   =  vibrationGroupTemp->clipCount2()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->vibration_clipCount2),  vibrationGroupTemp->clipCount2(), "vibration_clipCount2");

    //temp->vibration_clipCount3   =  vibrationGroupTemp->clipCount3()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->vibration_clipCount3),  vibrationGroupTemp->clipCount3(), "vibration_clipCount3");


    //temperature parameter
    FactGroup* temperatureTemp = vehicle1->temperatureFactGroup();
    VehicleTemperatureFactGroup*  temperatureGroupTemp = dynamic_cast<VehicleTemperatureFactGroup*>(temperatureTemp);
    //temp-> temperature1   =  temperatureGroupTemp->temperature1()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->temperature1),  temperatureGroupTemp->temperature1(), "temperature1");

    //temp->temperature2   = temperatureGroupTemp->temperature2()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->temperature2),  temperatureGroupTemp->temperature2(), "temperature2");

    //temp->temperature3   =  temperatureGroupTemp->temperature3()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->temperature3),  temperatureGroupTemp->temperature3(), "temperature3");


     //setpoint parameter
    FactGroup* setpointtemp = vehicle1->setpointFactGroup();
    VehicleSetpointFactGroup*  setpointGroupTemp = dynamic_cast<VehicleSetpointFactGroup*>(setpointtemp);
    //temp->setpoint_roll   =  setpointGroupTemp->roll()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->setpoint_roll),  setpointGroupTemp->roll(), "setpoint_roll");

    //temp->setpoint_pitch   =   setpointGroupTemp->pitch()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->setpoint_pitch),  setpointGroupTemp->pitch(), "setpoint_pitch");

    //temp->setpoint_yaw   =   setpointGroupTemp->yaw()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->setpoint_yaw),  setpointGroupTemp->yaw(), "setpoint_yaw");

    //temp->setpoint_rollRate   =   setpointGroupTemp->rollRate()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->setpoint_rollRate),  setpointGroupTemp->rollRate(), "setpoint_rollRate");

    //temp->setpoint_pitchRate    =   setpointGroupTemp->pitchRate()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->setpoint_pitchRate),  setpointGroupTemp->pitchRate(), "setpoint_pitchRate");

    //temp->setpoint_yawRate    =   setpointGroupTemp->yawRate()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->setpoint_yawRate),  setpointGroupTemp->yawRate(), "setpoint_yawRate");


    //distanceSensor parameter
    FactGroup* distanceSensortemp = vehicle1->distanceSensorFactGroup();
    VehicleDistanceSensorFactGroup*  distanceSensorGrouptemp = dynamic_cast<VehicleDistanceSensorFactGroup*>(distanceSensortemp);
    //temp->distanceSensor_rotationNone   =  distanceSensorGrouptemp->rotationNone()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->distanceSensor_rotationNone),  distanceSensorGrouptemp->rotationNone(), "distanceSensor_rotationNone");

    //temp->distanceSensor_rotationYaw45   =   distanceSensorGrouptemp->rotationYaw45()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->distanceSensor_rotationYaw45),  distanceSensorGrouptemp->rotationYaw45(), "distanceSensor_rotationYaw45");

    //temp->distanceSensor_rotationYaw90   =   distanceSensorGrouptemp->rotationYaw90()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->distanceSensor_rotationYaw90),  distanceSensorGrouptemp->rotationYaw90(), "distanceSensor_rotationYaw90");

    //temp->distanceSensor_rotationYaw135 =   distanceSensorGrouptemp->rotationYaw135()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->distanceSensor_rotationYaw135),  distanceSensorGrouptemp->rotationYaw135(), "distanceSensor_rotationYaw135");

    //temp->distanceSensor_rotationYaw180 =   distanceSensorGrouptemp->rotationYaw180()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->distanceSensor_rotationYaw180),  distanceSensorGrouptemp->rotationYaw180(), "distanceSensor_rotationYaw180");

    //temp->distanceSensor_rotationYaw225=   distanceSensorGrouptemp->rotationYaw225()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->distanceSensor_rotationYaw225),  distanceSensorGrouptemp->rotationYaw225(), "distanceSensor_rotationYaw225");

    //temp->distanceSensor_rotationYaw270=   distanceSensorGrouptemp->rotationYaw270()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->distanceSensor_rotationYaw270),  distanceSensorGrouptemp->rotationYaw270(), "distanceSensor_rotationYaw270");

    //temp->distanceSensor_rotationYaw315 =   distanceSensorGrouptemp->rotationYaw315()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->distanceSensor_rotationYaw315),  distanceSensorGrouptemp->rotationYaw315(), "distanceSensor_rotationYaw315");

    //temp->distanceSensor_rotationPitch90 =   distanceSensorGrouptemp->rotationPitch90()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->distanceSensor_rotationPitch90),  distanceSensorGrouptemp->rotationPitch90(), "distanceSensor_rotationPitch90");

    //temp->distanceSensor_rotationPitch270 =   distanceSensorGrouptemp->rotationPitch270()->rawValue().toDouble(&convertOk);
    saveValue(&(temp->distanceSensor_rotationPitch270),  distanceSensorGrouptemp->rotationPitch270(), "distanceSensor_rotationPitch270");


    temp->updateFlag = 1;



}

// convert the value of every uav to Json, and save at the send Queue
void  convertJson2SendQue(threadsafe_queue<QString>* sendMsgQueue1, VehicleInfo* temp)
{
    //QString VehicleInfoString ;

    json j;
    // save the vehicle info
    j["id"]= temp->id;
    j["roll"]= temp->roll;
    j["pitch"]= temp->pitch;
    j["heading"]= temp->heading;
    j["rollRate"]= temp->rollRate;
    j["pitchRate"]= temp->pitchRate;
    j["yawRate"]= temp->yawRate;
    j["groundSpeed"]= temp->groundSpeed;
    j["airSpeed"]= temp->airSpeed;
    j["climbRate"]= temp->climbRate;
    j["altitudeRelative"]= temp->altitudeRelative;
    j["altitudeAMSL"]= temp->altitudeAMSL;
    j["flightDistance"]= temp->flightDistance;
    j["flightTime"]= temp->flightTime;
    j["distanceToHome"]= temp->distanceToHome;
    j["gps_lat"]= temp->gps_lat;
    j["gps_lon"]= temp->gps_lon;
    j["gps_hdop"]= temp->gps_hdop;
    j["gps_vdop"]= temp->gps_vdop;
    j["gps_courseOverGround"]= temp->gps_courseOverGround;
    j["gps_count"]= temp->gps_count;
    j["gps_lock"]= temp->gps_lock;
    j["battery1_percentRemaining"]= temp->battery1_percentRemaining;
    j["battery1_mahConsumed"]= temp->battery1_mahConsumed;
    j["battery1_current"]= temp->battery1_current;
    j["battery1_temperature"]= temp->battery1_temperature;
    j["battery1_cellCount"]= temp->battery1_cellCount;
    j["battery1_instantPower"]= temp->battery1_instantPower;
    j["battery1_timeRemaining"]= temp->battery1_timeRemaining;
    j["battery1_chargeState"]= temp->battery1_chargeState;
    j["battery2_percentRemaining"]= temp->battery2_percentRemaining;
    j["battery2_mahConsumed"]= temp->battery2_mahConsumed;
    j["battery2_current"]= temp->battery2_current;
    j["battery2_temperature"]= temp->battery2_temperature;
    j["battery2_cellCoun"]= temp->battery2_cellCount;
    j["battery2_instantPower"]= temp->battery2_instantPower;
    j["battery2_timeRemaining"]= temp->battery2_timeRemaining;
    j["battery2_chargeState"]= temp->battery2_chargeState;
    j["ind_direction"]= temp->wind_direction;
    j["wind_speed"]= temp->wind_speed;
    j["wind_verticalSpeed"]= temp->wind_verticalSpeed;
    j["vibration_xAxis"]= temp->vibration_xAxis;
    j["vibration_yAxis"]= temp->vibration_yAxis;
    j["vibration_zAxis"]= temp->vibration_zAxis;
    j["vibration_clipCount1"]= temp->vibration_clipCount1;
    j["vibration_clipCount2"]= temp->vibration_clipCount2;
    j["vibration_clipCount3"]= temp->vibration_clipCount3;
    j["temperature1"]= temp->temperature1;
    j["temperature2"]= temp->temperature2;
    j["temperature3"]= temp->temperature3;
    j["setpoint_roll"]= temp->setpoint_roll;
    j["setpoint_pitch"]= temp->setpoint_pitch;
    j["setpoint_yaw"]= temp->setpoint_yaw;
    j["setpoint_rollRate"]= temp->setpoint_rollRate;
    j["setpoint_pitchRate"]= temp->setpoint_pitchRate;
    j["setpoint_yawRate"]= temp->setpoint_yawRate;
    j["distanceSensor_rotationNone"]= temp->distanceSensor_rotationNone;
    j["distanceSensor_rotationYaw45"]= temp->distanceSensor_rotationYaw45;
    j["distanceSensor_rotationYaw90"]= temp->distanceSensor_rotationYaw90;
    j["distanceSensor_rotationYaw135"]= temp->distanceSensor_rotationYaw135;
    j["distanceSensor_rotationYaw180"]= temp->distanceSensor_rotationYaw180;
    j["distanceSensor_rotationYaw225"]= temp->distanceSensor_rotationYaw225;
    j["distanceSensor_rotationYaw270"]= temp->distanceSensor_rotationYaw270;
    j["distanceSensor_rotationYaw315"]= temp->distanceSensor_rotationYaw315;
    j["distanceSensor_rotationPitch90"]= temp->distanceSensor_rotationPitch90;
    j["distanceSensor_rotationPitch270"]= temp->distanceSensor_rotationPitch270;



    // json2string
    std::string s = j.dump(4);
    QString qstr2 = QString::fromStdString(s);
    sendMsgQueue1->push(qstr2);
}


void ReadUAVDataThread::run()
{
//    QmlObjectListModel* vehiclesObject;

//    VehicleInfo temp;


    qDebug()<<"myThread run() start to execute";

    qDebug()<<"current thread ID:"<<QThread::currentThreadId()<<'\n';
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
     qdebug2("get myVehicles  and myMultiVehicleManager");


    while(1)
    {
        QThread::sleep(2);
        qdebug2("wait to read  last data") ;


        if ( myMultiVehicleManager->activeVehicleAvailable())
            {
                qdebug2("activeVehicleAvailable");
                // clear all,wait new datas
                // rewrite a  clear function to delete the space

//              // get current active Vehicle
                myActiveVehicle  =  myMultiVehicleManager->activeVehicle();

                qdebug2("myVehicles count:%d", myVehicles->count());

                for (int i=0; i< myVehicles->count(); i++)
                {
                    Vehicle* vehicle = qobject_cast<Vehicle*>((*myVehicles)[i]);
                    // change the data to  our format ,and save
                    VehicleInfo *temp = new VehicleInfo();
                    saveAsVehicleInfo(vehicle, temp);
                    convertJson2SendQue( &sendMsgQueue, temp);

                }

            }
        else
            {//now ,there is no active vehicle,wait next time
                qdebug2("activeVehicleUnavailable()");
                continue;
            }
    }



        exec();
}
