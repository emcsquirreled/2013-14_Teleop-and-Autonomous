#include "Logger.h"

writeCurrentHeading(1);

bool gatheringData = true;

void setGatheringData(bool gathering);

task getHeading () {
	//Continuously calculates haeding based on the values given from the gyro
	//Delta is greek and means "change in"
	HTGYROstartCal(GYRO);
	float deltaTime = 0;
	float prevHeading = 0;
	float currRate = 0;
	time1[T4] = 0;
  while (true) {
  	//Reads the value from the gyro
 		//It returns a value in rotations per second
  	//Thusly we can multiply the value we get by the amount of time since the last time we did this part
  	//and get out the change in heading
    currRate = HTGYROreadRot(GYRO);
    //Only except values bigger than five or less than negative five,
    //and only except values when value gathering is enabled
    if (gatheringData == true){
    	if (abs(currRate) > 5 || abs(currRate) < -5) {

      	prevHeading = getCurrentHeading();
      	writeCurrentHeading(prevHeading + currRate * deltaTime);

      	if (getCurrentHeading() > 360) getCurrentHeading() -= 360;
      	else if (getCurrentHeading() < 0) getCurrentHeading() += 360;
    	}
  	}
  	//This calculates the amount of time in seconds since this part of the code as last run
  	//For some reason it breaks if you put it at the begining of the code, so its here
    wait1Msec(1);
    deltaTime = ((float)time1[T4]) / 1000.0;
    time1[T4] = 0;
    log_integer(getCurrentHeading());
    log_integer(deltaTime*1000);
		log_integer(currRate);
  }
}

void setGatheringData(bool gathering){
	gatheringData = gathering;
}
