
float distanceF2 = 0;

task Distance()

{

	float holder2;

	float holder3;

	const float WheelCir = 12.55;

	nMotorEncoder[motorA] = 0;

	while(true)

	{

		while(getMovement() != 2) // while robot is moving

		{
			distanceF2 = nMotorEncoder[motorA];  // puts degrees from motor B into variable distance

			nxtDisplayTextLine(1, "distance:  %f", getDistance());


		}


		if(getMovement() == 2)

		{

			holder2 = distanceF2 / 360;       //covert degrees to rotations

			holder3 = WheelCir * holder2;    //get the distance of inches traveled

			writeDistance(holder3 * 2 / 3);
		}

  	nxtDisplayCenteredTextLine(2, "Dist2.  %f", getDistance());

	}





}
