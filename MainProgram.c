#pragma config(Hubs,  S1, HTMotor,  HTServo,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     accel,          sensorI2CCustom)
#pragma config(Sensor, S3,     GYRO,           sensorAnalogInactive)
#pragma config(Sensor, S4,     IR,             sensorI2CCustom)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorH,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorI,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,      elevatorElevator,             tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,      ,             tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


//#include "BlockCount.h"
#include "hitechnic-accelerometer.h"
#include "hitechnic-gyro.h"
#include "hitechnic-irseeker-v1.h"
#include "hitechnic-irseeker-v2.h"
#include "Robot.h"
#include "Direction.h"
#include "Logger.h"
#include "Navigation.h"
//#include "ObstacleAvoidance.h"
#include "Paths.h"
#include "beaconDetection.h"
#include "common.h"
#include "distance.h"
#include "Position.h"
#include "TurnAngle.h"
#include "distancego.h"

#include "JoystickDriver.c"
#include "IRandRamp.h"




task main()
{


StartTask(IRandRamp);


}
