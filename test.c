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


#include "TurnAngle.h"

task main()
{
HTGYROstartCal(GYRO);
StartTask(getHeading);

motor[motorD] = 75;
motor[motorE] = 75;

wait1Msec(1000);

motor[motorD] = 0;
motor[motorE] = 0;


TurnAngle(90, true);

wait1Msec(400);

TurnAngle(-90, false);

motor[motorD] = 0;
motor[motorE] = 0;


}
