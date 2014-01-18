
void Test()


{

	StartTask(Collision);

	while(getMovement() != 2)
	{

		nxtDisplayCenteredTextLine(5, "%f", getMovement());
		motor[motorD] = 55;
		motor[motorE] = 55;


	}

	motor[motorE] = 0;
	motor[motorD] = 0;

	reachHeading(90);

	wait1Msec(500);

	reachHeading(0);

	wait1Msec(500);

	driveDistance(12, 75);

	wait1Msec(500);

	driveDistance(12, -75);



}
