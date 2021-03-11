#include "vehicleinfo.h"


VehicleInfo::VehicleInfo()
{
    updateFlag = 0;

    id = 0;
    active = 0;

    roll = 0;
    pitch = 0;
    heading = 0;
    rollRate = 0;
    pitchRate = 0;
    yawRate = 0;
    groundSpeed = 0;
    airSpeed = 0;
    climbRate = 0;
    altitudeRelative = 0;
    altitudeAMSL = 0;
    flightDistance = 0;
    flightTime = 0;
    distanceToHome = 0;
    //hobbs = 0;

    //gps parameter
    gps_lat = 0;
    gps_lon = 0;
    gps_hdop = 0;
    gps_vdop = 0;
    gps_courseOverGround = 0 ;
    gps_count = 0;
    gps_lock = 0;

    //battery1 parameter
    battery1_percentRemaining = 0 ;
    battery1_mahConsumed = 0  ;
    battery1_current = 0  ;
    battery1_temperature  = 0 ;
    battery1_cellCount  = 0 ;
    battery1_instantPower = 0  ;
    battery1_timeRemaining = 0  ;
    battery1_chargeState = 0  ;

    //battery2 parameter
    battery2_percentRemaining = 0 ;
    battery2_mahConsumed = 0  ;
    battery2_current = 0  ;
    battery2_temperature = 0  ;
    battery2_cellCount = 0  ;
    battery2_instantPower = 0  ;
    battery2_timeRemaining = 0  ;
    battery2_chargeState = 0  ;


    //wind parameter
    wind_direction = 0 ;
    wind_speed = 0 ;
    wind_verticalSpeed = 0 ;

    //vibration parameter
    vibration_xAxis = 0 ;
    vibration_yAxis = 0 ;
    vibration_zAxis = 0 ;
    vibration_clipCount1 = 0 ;
    vibration_clipCount2 = 0 ;
    vibration_clipCount3 = 0 ;

    //temperature parameter
    temperature1 = 0 ;
    temperature2 = 0 ;
    temperature3 = 0 ;

//    //clock parameter
//    double           clock ;

    //setpoint parameter
    setpoint_roll = 0 ;
    setpoint_pitch = 0 ;
    setpoint_yaw = 0 ;
    setpoint_rollRate = 0 ;
    setpoint_pitchRate = 0 ;
    setpoint_yawRate = 0 ;

//    //distanceSensor parameter
    distanceSensor_rotationNone  = 0;
    distanceSensor_rotationYaw45 = 0;
    distanceSensor_rotationYaw90 = 0;
    distanceSensor_rotationYaw135 = 0;
    distanceSensor_rotationYaw180 = 0;
    distanceSensor_rotationYaw225 = 0;
    distanceSensor_rotationYaw270 = 0 ;  
    distanceSensor_rotationYaw315  = 0;
    distanceSensor_rotationPitch90  = 0; 
    distanceSensor_rotationPitch270  = 0; 
}
