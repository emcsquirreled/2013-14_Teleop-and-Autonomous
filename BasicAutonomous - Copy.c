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
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "Navigation.h"
#include "distance.h"
#include "beaconDetection.h"

task main()
{
	HTGYROstartCal(GYRO);
	StartTask(getHeading);
	StartTask(Distance);
	StartTask(Collision);
	motor[motorD] = 50;
	motor[motorE] = -50;
	time1[T3] = 0;
	while (atBeacon() == false && movement != 2 && time1[T3] < 50000000) {
		wait1Msec(2);
	}
	if (movement == 2){

	}
	movement = 2;
	motor[motorD] = 0;
	motor[motorE] = 0;
	while(distance == 0){
		wait1Msec(1);
	}
	movement = 0;
	distance = distance - 3;
	StopTask(Distance);
	reachHeading(90);
	driveDistance(5, 50);
	motor[motorC] = 100;
	wait1Msec(3000);
	motor[motorC] = 0;
	driveDistance(5, -50);
	PlaySound(soundBeepBeep);
	reachHeading(0);
	driveDistance(56 - abs(distance), 75);
	reachHeading(45);
	driveDistance(16, 75);
	reachHeading(90);
	driveDistance(24, 75);
	reachHeading(170);
	StopTask(Collision);
	driveDistance(32, 75);
	StopAllTasks();
}
