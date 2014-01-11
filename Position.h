/*
@This Function tells the robot its X & Y position on the field.

 --The field is 12ft by 12ft field, the program breaks the field dimensions into inches (144in by 144in) and does its stuff in inches, making for more precise measurements.

@This function creates a global variables "X" & "Y" which stores the robots X position and Y position.

@This function is used by ObstacleAvoidance.h & CollisionDetect.h

*/

#include "Quadrant.h"


float distanceF;

float degree = 0;

const float WheelCir = 10.205;  //Enter wheel circumference in inches

task Get_Position()

{


//Define variables//
	float distance = 0;

	float sin_cos;

	int degrees;

	int motor_A;

	int motor_B;

	int holder;

	float Ytemp;

	float Xtemp;

	float holder2;

	//float currHeading;

	float holder3 = 0;

//Start tasks//
	HTGYROstartCal(GYRO);
	StartTask(getHeading);

	StartTask(Quadrant);

	StartTask(Collision);


	Ytemp = 0;

	Xtemp = 0;


	while(1==1) // repeat forever

	{


// zero out all the variables//

		holder3 = 0;

		holder = 0;

		motor_A = 0;

		motor_B = 0;

		sin_cos = 0;

		holder2 = 0;

		writeCurrentHeading(0);





		if(getMovement() != 2)  // if robot is moving

		{
			nMotorEncoder[motorB] = 0;

			while(getMovement() != 2) // while robot is moving

			{
				distanceF = nMotorEncoder[motorB];  // puts degrees from motor B into variable distance

				nxtDisplayTextLine(1, "distance:  %f", distanceF);

				if(getMovement() == 2)

				{
					break;
				}

			}


		}


		if(getMovement() == 2)   // if robot is stopped

		{


			if(Quadrant == 1)
			{

				holder2 = distanceF / 360;       //covert degrees to rotations

				distanceF = WheelCir * holder2;    //get the distance of inches traveled

				degree = distanceF;

				sin_cos = sin(getCurrentHeading());       //  get the sin from the numbers of degrees turned

				Xtemp = sin_cos * distanceF;      // multiply the sin by the number of distance travled and put it in the X variable

				sin_cos = 0;                // set the sin_cos variable to zero

				sin_cos = cos(getCurrentHeading());    // get the cos from the numbers of degrees turned

				Ytemp = sin_cos * distanceF;   //  multiply the cos by the number of distance travled and put it in the Y variable

				writeY(Ytemp + getY());              // adds the past value of Y to Y

				writeX(Xtemp + getX());              // adds the past value of X to X



			}


			else if(Quadrant == 2)

			{

				holder2 = distanceF / 360;       //covert degrees to rotations

				distanceF = WheelCir * holder2;    //get the distance of inches traveled

				degrees = distanceF;       //put distanceF value into degrees variable

				sin_cos = sin(getCurrentHeading());       //  get the sin from the numbers of degrees turned

				Ytemp = sin_cos * distanceF;      // multiply the sin by the number of distance travled and put it in the Y variable

				sin_cos = 0;                // set the sin_cos variable to zero

				sin_cos = cos(getCurrentHeading());    // get the cos from the numbers of degrees turned

				Xtemp = sin_cos * distanceF;   //  multiply the cos by the number of distance travled and put it in the X variable

				Ytemp = -1 * Ytemp;          //makes Y a negitive

				writeY(Ytemp + getY());              // adds the past value of Y to Y

				writeX(Xtemp + getX()); // adds the past value of X to X



			}




			else if(Quadrant == 3)

			{

				holder2 = distanceF / 360;       //covert degrees to rotations

				distanceF = WheelCir * holder2;    //get the distance of inches traveled

				degrees = getCurrentHeading();       //put distanceF value into degrees variable

				sin_cos = sin(getCurrentHeading());       //  get the sin from the numbers of degrees turned

				Xtemp = sin_cos * distanceF;      // multiply the sin by the number of distance travled and put it in the X variable

				sin_cos = 0;                // set the sin_cos variable to zero

				sin_cos = cos(getCurrentHeading());    // get the cos from the numbers of degrees turned

				Ytemp = sin_cos * distanceF;   //  multiply the cos by the number of distance travled and put it in the Y variable

				Ytemp = -1 * Ytemp;          //makes Y negitive

				Xtemp = -1 * Xtemp;          //makes X negitive

				writeY(Ytemp + getY());              // adds the past value of Y to Y

				writeX(Xtemp + getX());              // adds the past value of X to X



			}



			else if(Quadrant == 4)

			{

				holder2 = distanceF / 360;       //covert degrees to rotations

				distanceF = WheelCir * holder2;    //get the distance of inches traveled

				degrees = getCurrentHeading();       //put currHeading value into degrees variable

				sin_cos = sin(getCurrentHeading());       //  get the sin from the numbers of degrees turned

				Ytemp = sin_cos * distanceF;      // multiply the sin by the number of distance travled and put it in the X variable

				sin_cos = 0;                // set the sin_cos variable to zero

				sin_cos = cos(getCurrentHeading());    // get the cos from the numbers of degrees turned

				Xtemp = sin_cos * distanceF;   //  multiply the cos by the number of distance travled and put it in the Y variable

				Xtemp = -1 * Xtemp;         //makes X negitive

				writeY(Ytemp + getY());              // adds the past value of Y to Y

				writeX(Xtemp + getX());              // adds the past value of X to X



			}

		}

	}
	// Tasks by default take as much cpu time as they need
	// This wait allows time for other stuff to get done
	wait1Msec(5);

}
