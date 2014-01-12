#pragma config(Hubs,  S1, HTMotor,  HTServo,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,   HTSMUX,               sensorI2CCustom)
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


#include "hitechnic-sensormux.h"

const tMUXSensor GYRO = msensor_S3_4;
const tMUXSensor accel = msensor_S3_3;
const tMUXSensor IR = msensor_S3_2;

#include "JoystickDriver.c"
#include "Navigation.h"
#include "distance.h"
#include "beaconDetection.h"

int olddistance = 0;

task main()
{
	StartTask(getHeading);
	StartTask(Distance);
 // waitForStart();   //&&&&&&&&&&&&&&  	COMMENT OUT IF TESTING &&&&&&&&&&&&&&&&&&&&&&&//
	motor[elevatorElevator] = -60;
	wait1Msec(2000);
	motor[elevatorElevator] = 0;
	motor[motorE] = 50;
	motor[motorD] = -50;
	motor[motorA] = -50;
	time1[T3] = 0;
	while (atBeacon() == false && time1[T3] < 2500) {
		wait1Msec(2);
	}
	if (time1[T3] >= 5000){
		StopAllTasks();
	}
	movement = 2;
	wait1Msec(25);
	StopTask(Distance);
	//distance = distance - 5;
	olddistance = distance;
	distance = 50 - abs(distance);

	if (abs(olddistance) > 25) {
		//driveDistance(2, -75);
	}else{
		driveDistance(7, -75);
	}
	reachHeading(270);
	//driveDistance(5, -75);
	motor[motorA] = -50;
	motor[motorD] = -50;
	motor[motorE] = 50;
	wait1Msec(750);
	motor[motorA] = 0;
	motor[motorD] = 0;
	motor[motorE] = 0;
	StartTask(Collision);
	wait1Msec(250);
	Set = -44;
	while(movement != 2)
	{
		motor[motorA] = 50;
		motor[motorD] = 50;
		motor[motorE] = -50;
		wait1Msec(10);
	}
	motor[motorA] = 0;
	motor[motorD] = 0;
	motor[motorE] = 0;
	PlaySound(soundBeepBeep);
	StopTask(Collision);
	wait1Msec(250);
	nMotorEncoder[motorC] = 0;
	//while(abs(nMotorEncoder[motorC]) <= 600) //540
	//{
	//	motor[motorC] = 100;
	//}
	//motor[motorC] = 0;
	//wait1Msec(250);
	//while(abs(nMotorEncoder[motorC]) >= 10) //2
	//{
	//	motor[motorC] = -100;
	//}
	motor[motorC] = -100;
	wait10Msec(200);
	motor[motorC] = 100;
	driveDistance(12, -75);
	reachHeading(183);
	wait1Msec(500);
	StartTask(Collision);
	wait1Msec(250);
	Set = -75;
	driveDistance(distance, 50);   //&&&&&&&&&
	wait1Msec(250);
	reachHeading(230);
	wait1Msec(250);
	driveDistance(22, 50);
	reachHeading(270);
	wait1Msec(250);
	driveDistance(30, 50);
	reachHeading(350);
	StopTask(Collision);
	motor[motorA] = 75;
	motor[motorD] = 75;
	motor[motorE] = -75;
	wait10Msec(150);
	motor[motorD] = 0;
	motor[motorE] = 0;
	motor[motorA] = 0;
	StopAllTasks();
}
