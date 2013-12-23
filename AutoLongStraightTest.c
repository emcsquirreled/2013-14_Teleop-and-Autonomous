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
#pragma config(Motor,  mtr_S1_C4_1,      ,             tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,      ,             tmotorTetrix, openLoop)

#include "Navigation.h"


task main()
{

	StartTask(Collision);
	//StartTask(getHeading);
	//wait1Msec(1000);
	driveDistance(36, 75);
	//reachHeading(92);
	//reachHeading(270);

}
