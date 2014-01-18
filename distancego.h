/*
@This function makes the robot go for certain distance in cm.

	--TO USE: use cmDistance(20, 100) This makes the robot go forward for 20cm at 100% power.
	--First in the pragma is centimeters wanted to go and the second is the motor power.

*/




void cmDistance(float cm, int speed)
{

//Set wheel circumference in inches//
	const float WheelCir = 27.9146;

//Define variables//
	float holder = 0;

	float distance = 0;

	float goal = 0;

//convert inches to centimeters//
	distance = cm * 2.54;

//Do equation to calculate how many rotations it needs to do//
	holder = WheelCir / distance;

	goal = holder * 360;

//Zero encoder//
	nMotorEncoder[motorB] = 0;
	nMotorEncoder[motorA] = 0;

//While the encoder is less then the goal//
	while((abs(nMotorEncoder[motorB]) + abs(nMotorEncoder[motorA])) / 2 < goal)

	{

//Set speed from the pragma to the motors//
		nxtDisplayCenteredTextLine(5, "dist.  %f", goal);
		motor[motorD] = speed;
		motor[motorE] = speed;
		motor[motorB] = speed;
		motor[motorA] = speed;

	}

//Stop motors//
	motor[motorD] = 0;
	motor[motorE] = 0;
	motor[motorB] = 0;
	motor[motorA] = 0;





}
