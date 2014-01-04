/*
@This function breaks 360 degrees into 4 Quadrents.
 -- Quadrent #1 = 0-90 degrees
 -- Quadrent #2 = 90-180 degrees
 -- Quadrent #3 = 180-270 degrees
 -- Quadrent #4 = 270-360 degrees

@This function gives out a global variable "Quadrent" which has the quadrent number.

@This is used by Position.h to figure out what quadrent its in.
*/



#include "Collision.h"


int Quadrant = 0;


task ReadData()

{

	HTGYROstartCal(GYRO);
	StartTask(getHeading);

	while(true)

	{








/*If the value is less then 90 degrees AND greater or eual to zero
									Write #1 in variable Quadrent */
		if(currentHeading < 90 && currentHeading >= 0)

		{

			Quadrant = 1;

		}
/*If the value is greater than 90 degrees AND less than 180 degrees
									Write #2 in variable Quadrent */

		else if(currentHeading > 90 && currentHeading < 180)

		{

			Quadrant = 2;

		}

/*If the value is greater than 180 degrees AND less than 270 degrees
									Write #3 in variable Quadrent */
		else if(currentHeading > 180 && currentHeading < 270)

		{

			Quadrant = 3;

		}

/*If the value is greater than 270 degrees AND less than 361
				Write value #4 in variable Quadrent */
		else if(currentHeading > 270 && currentHeading < 361)

		{

			Quadrant = 4;

		}










	}









}
