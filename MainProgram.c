#pragma config(Hubs,  S1, HTMotor,  HTServo,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     HTSMUX,         sensorI2CCustom)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop, reversed, encoder)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_1,     motorH,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorI,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     elevatorElevator, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motorI,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//#include "BlockCitechount.h"
#include "hitechnic-sensormux.h"

const tMUXSensor GYRO = msensor_S3_4;
const tMUXSensor accel = msensor_S3_3;
const tMUXSensor IR = msensor_S3_2;


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
//#include "Position.h"
#include "TurnAngle.h"
#include "distancego.h"
#include "Collision.h"
#include "JoystickDriver.c"
#include "IRandRamp.h"
#include "Test.h"



task main()
{

Test();

//IRandRamp();


}
