#ifndef VEHICLEINFO_H
#define VEHICLEINFO_H

#include <QObject>

class VehicleInfo :  public QObject
{
   //  Q_OBJECT
public:
    VehicleInfo();

    // 1:update ok,0 :faild
    int updateFlag;

    int     id;
    bool    active;
    double roll ;
    double pitch ;
    double heading ;
    double rollRate ;
    double pitchRate ;
    double yawRate ;
    double groundSpeed ;
    double airSpeed ;
    double climbRate ;
    double altitudeRelative ;
    double altitudeAMSL ;
    double flightDistance ;
    double flightTime ;
    double distanceToHome ;
    //double hobbs ;

    //gps parameter
    double             gps_lat ;
    double             gps_lon;
    double             gps_hdop;
    double             gps_vdop;
    double             gps_courseOverGround ;
    double             gps_count;
    double             gps_lock;

    //battery1 parameter
    double         battery1_percentRemaining ;
    double         battery1_mahConsumed  ;
    double         battery1_current  ;
    double         battery1_temperature  ;
    double         battery1_cellCount  ;
    double         battery1_instantPower  ;
    double         battery1_timeRemaining  ;
    double         battery1_chargeState  ;

    //battery2 parameter
    double         battery2_percentRemaining ;
    double         battery2_mahConsumed  ;
    double         battery2_current  ;
    double         battery2_temperature  ;
    double         battery2_cellCount  ;
    double         battery2_instantPower  ;
    double         battery2_timeRemaining  ;
    double         battery2_chargeState  ;


    //wind parameter
    double            wind_direction ;
    double            wind_speed ;
    double            wind_verticalSpeed ;

    //vibration parameter
    double       vibration_xAxis ;
    double       vibration_yAxis ;
    double       vibration_zAxis ;
    double       vibration_clipCount1 ;
    double       vibration_clipCount2 ;
    double       vibration_clipCount3 ;

    //temperature parameter
    double     temperature1 ;
    double     temperature2 ;
    double     temperature3 ;

//    //clock parameter
//    double           clock ;

    //setpoint parameter
    double        setpoint_roll ;
    double        setpoint_pitch ;
    double        setpoint_yaw ;
    double        setpoint_rollRate ;
    double        setpoint_pitchRate ;
    double        setpoint_yawRate ;

//    //distanceSensor parameter
    double distanceSensor_rotationNone ;
    double distanceSensor_rotationYaw45;
    double distanceSensor_rotationYaw90;
    double distanceSensor_rotationYaw135;
    double distanceSensor_rotationYaw180;
    double distanceSensor_rotationYaw225;
    double distanceSensor_rotationYaw270 ;  
    double distanceSensor_rotationYaw315 ;
    double distanceSensor_rotationPitch90 ; 
    double distanceSensor_rotationPitch270 ; 

};

#endif // VEHICLEINFO_H
