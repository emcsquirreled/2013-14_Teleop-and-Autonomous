#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S3,     GYRO,           sensorAnalogInactive)
#pragma config(Sensor, S4,     IR,             sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "beaconDetection.h"
#include "TurnAngle.h"
#include <JoystickDriver.c>

task main()
{
waitForStart();
	HTGYROstartCal(GYRO);
	StartTask(getHeading);
	motor[motorD] = 100;
	motor[motorE] = 100;
	time1[T3] = 0;

	while (atBeacon() == false && time1[T3] < 5000) {
		wait1Msec(2);
	}
	wait1Msec(450);

	float time = time1[T3];

	motor[motorD] = -100;
	motor[motorE] = 100;

	if(time < 3000)
	{
		wait1Msec(1250);
	}

	else
	{

		wait1Msec(1400);

	}

	motor[motorD] = 0;
	motor[motorE] = 0;
	///////////////////////
	motor[motorD] = 80;
	motor[motorE] = 80;

	if(time < 3000)
	{
		wait1Msec(650);
	}

	else
	{

		wait1Msec(1250);

	}

	motor[motorD] = 0;
	motor[motorE] = 0;

	motor[motorC] = -100;

	wait1Msec(2000);

	motor[motorC] = 0;

	motor[motorD] = -50;
	motor[motorE] = -50;

	wait1Msec(1000);

	motor[motorD] = 0;
	motor[motorE] = 0;

}
