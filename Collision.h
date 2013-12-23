
#include "Accel_Read.h"

int movement = 0;

int Set = -75; //set to threshold --- default is -75

task Collision()

{

	movement = 0;

	StartTask(Accel_Read);


	//wait1Msec(5);

	while(true)

	{

		if(X > 80)

		{

			movement = 1;

		}

		else if(X < Set) // real value is -75

		{

			movement = 2;


		}


		else if(X > -4 && X < 12)

		{


			movement = 0;

		}



		wait1Msec(5);

	}



}
