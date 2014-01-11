

/*
@This code is a function that you call to make the robot turn in degrees. TO USE: use TurnAngle(-90, true) This makes the robot turn -90 degrees to the left.  First in the pragma is degrees wanted to turn and the second is a bool telling the robot to turn left or right (TRUE=Left FAlSE=Right)

 --SEE BELOW FOR COLOR RULE---
*/
void TurnAngle(int Goal1, bool Adirection)
{

	// Set variables //
	int holder3 = 0;

	int holder4 = 0;

	int Goal2;

	// add the degrees wanted to go with the current degree heading and put that value into Goal2 //
	Goal2 = (int) getCurrentHeading() + Goal1;


	// If the Goal2 value exceeds 360 it will convert the value to something the Direction program can work with //
	if(Goal2 > 360)

	{
		holder3 = Goal2 - 360;

		Goal2 = 0;

		Goal2 = holder3;


	}

	// If the Goal2 value is less than 0 it will convert the value to something the Direction program can work with //
	else if(Goal2 < 0)

	{

		holder3 = abs(Goal2);

		holder4 = holder3 - (int) getCurrentHeading();

		Goal2 = 0;

		Goal2 = 360 - holder4;

	}


	//////////////////////////////////////////////////////////////////////


	// If if the turn direction is set to go left (true) //

	if(Adirection == true)

	{


		while((int) getCurrentHeading() != Goal2 + 3 && Goal2 - 3 )

		{
			motor[motorD] = 100;		//make positive if on blue and make negitive if on red
			motor[motorE] = -100;   //make negitive if on blue and make positive if on red
		}


		motor[motorD] = 0;
		motor[motorE] = 0;



	}


	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



	// If the turn direction is set to go right (false) //

	if(Adirection == false)

	{

		while((int) getCurrentHeading() != Goal2 + 3 && Goal2 - 3)

		{

			motor[motorD] = -100; //make negitive if on blue and make positive if on red
			motor[motorE] = 100;  //make positive if on blue and make negitive if on red

		}


		motor[motorD] = 0;
		motor[motorE] = 0;



	}





}
