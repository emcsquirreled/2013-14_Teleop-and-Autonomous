// Includes
#include "ObstacleAvoidance.h"
#include "Direction.h"
#include "Collision.h"

// Constants
float GEARRATIO = 1.5;
float offsetFactorTurning = 10.5;

// Variables
int previousGoalHeading = 0;
int direction = 0;

void driveDistance(int inches, int power);

void reachHeading(int goalHeading);

void driveDistance(int inches, int power){
	//Tells the robot to drive a certain distance based on parameters specified
	//The value for power has no effect on distance traveled theoretically
	//In practice it overshoots slightly more with higher power levels
	movement = 0;
	wait10Msec(5);
	nMotorEncoder[motorA] = 0; // It is good practice to reset encoder values at the start of a function.
	//Calculate inches by multiplying the ratio we determined earlier with the amount of
	//inches to go, then divide the circumference of the wheel.
	//Since we don't want to calculate every iteration of the loop, we will find the clicks needed
	//before we begin the loop.

	//This line is just for error correction
	inches = inches + -4.5;

	//Here is the actual calculation
	int tickGoal = ((360.0 * inches ) / 12.12);

	//Our encoder is on a different sized sprocket from our wheels and motors
	//This corrects for the gear differences
	tickGoal *= GEARRATIO;

	//Waits until we have moved farther than the goal number of ticks
	//It will also stop if we aren't going backwards and we detect a collision
	while(abs(nMotorEncoder[motorA]) < tickGoal && (movement != 2 || power < 0))
	{
		motor[motorD] = power;  // The nice thing about encoders is that we can use any power value we want, and
		motor[motorE] = -power; // still get the same distance.
		motor[motorA] = power;
	}
	if (movement == 2 && power > 0){
		StopAllTasks();
	}
	motor[motorE] = 0;
	motor[motorD] = 0;
	motor[motorA] = 0;
	wait10Msec(2);
}

void reachHeading(int goalHeading){
	//Turns on the heading calculation system
	setGatheringData(true);
	//Make all values positive and less than 360
	while(goalHeading>360){
		goalHeading-=360;
	}
	while(goalHeading<0){
		goalHeading+=360;
	}
	//This next bunch of code simply calculates whether it is optimal to go left or to go right
	int staticCurrentHeading = currentHeading;
	if (staticCurrentHeading < goalHeading) {
		staticCurrentHeading += 360;
	}
	int left = staticCurrentHeading - goalHeading;
	if (left > 180){
		direction = -1;
	}else{
		direction = 1;
	}
	//Starts the motors, changing direction depending on the value calculated in the previous section of code
	motor[motorD] = 100 * direction;
	motor[motorE] = 100 * direction;
	motor[motorA] = -100 * direction;
	//Waits for the robot to be facing the correct direction
	while (abs(goalHeading - currentHeading) > offsetFactorTurning){
		log_integer(currentHeading);
		wait1Msec(1);
	}
	//Resets everything and prepares the robot for continued movement and turning
	motor[motorD] = 0;
	motor[motorE] = 0;
	motor[motorA] = 0;
	wait10Msec(20);
	setGatheringData(false);
	previousGoalHeading = goalHeading;
}
