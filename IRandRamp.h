

int olddistance = 0;

 void IRandRamp()
{
	StartTask(getHeading);
	StartTask(Distance);
  waitForStart();   //&&&&&&&&&&&&&&  	COMMENT OUT IF TESTING   &&&&&&&&&&&&&&&&&&&&&&&//
	motor[elevatorElevator] = -60;
	wait1Msec(750);
	motor[elevatorElevator] = 0;
	motor[motorE] = -50;
	motor[motorD] = -50;
	motor[motorA] = -50;
	motor[motorB] = -50;
	time1[T3] = 0;
	while (atBeacon() == false && time1[T3] < 2500) {
		wait1Msec(2);
	}
	if (time1[T3] >= 5000){
		StopAllTasks();
	}
	writeMovement(2);
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
	motor[motorE] = -50;
	motor[motorB] = -50;
	wait1Msec(750);
	motor[motorA] = 0;
	motor[motorD] = 0;
	motor[motorE] = 0;
	motor[motorB] = 0;
	StartTask(Collision);
	wait1Msec(250);
	writeCollisionThreshold(-44);
	while(getMovement() != 2)
	{
		motor[motorA] = 50;
		motor[motorD] = 50;
		motor[motorE] = 50;
		motor[motorB] = 50;
		wait1Msec(10);
	}
	motor[motorA] = 0;
	motor[motorD] = 0;
	motor[motorE] = 0;
	motor[motorB] = 0;
	PlaySound(soundBeepBeep);
	StopTask(Collision);
	wait1Msec(250);
	nMotorEncoder[motorC] = 0;
	while(abs(nMotorEncoder[motorC]) <= 1000) //540
	{
		motor[motorC] = 100;
	}
	motor[motorC] = 0;
	wait1Msec(250);
	driveDistance(12, -75);
	reachHeading(183);
	wait1Msec(500);
	StartTask(Collision);
	wait1Msec(250);
	writeCollisionThreshold(-75);
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
	motor[motorE] = 75;
	motor[motorB] = 75;
	wait10Msec(150);
	motor[motorD] = 0;
	motor[motorE] = 0;
	motor[motorA] = 0;
	motor[motorB] = 0;
	StopAllTasks();
}
