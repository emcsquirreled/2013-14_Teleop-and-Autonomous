
#include "Accel_Read.h"

task Collision()

{

	writeMovement(0);

	StartTask(Accel_Read);


	//wait1Msec(5);

	while(true)

	{

		if(x_accel > 80)

		{

			writeMovement(1);

		}

		else if(x_accel < getCollisionThreshold()) // real value is -75

		{

			writeMovement(2);


		}


		else if(x_accel > -4 && x_accel < 12)

		{


			writeMovement(0);

		}



		wait1Msec(5);

	}



}
