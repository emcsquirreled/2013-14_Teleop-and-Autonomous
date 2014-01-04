
#include "Accel_Read.h"

task Collision()

{

	writeMovement(0);

	StartTask(Accel_Read);


	//wait1Msec(5);

	while(true)

	{

		if(X > 80)

		{

			writeMovement(1);

		}

		else if(X < Set) // real value is -75

		{

			writeMovement(2);


		}


		else if(X > -4 && X < 12)

		{


			writeMovement(0);

		}



		wait1Msec(5);

	}



}
