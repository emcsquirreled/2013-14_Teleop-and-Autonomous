






bool atBeacon(void) {
	/* Declare variables */
	int zones[5];
	int average = 0;
	bool atBeacon = false;
  bool inRange = false;
	/* Read the infrared seeker into an array */
	//HTIRS2readAllACStrength(IR, zones[0], zones[1], zones[2], zones[3], zones[4]);
	HTIRS2readAllACStrength(IR, zones[4], zones[3], zones[2], zones[1], zones[0]);

	/* Find the average infrared noise level */
	for(int i = 0; i < 5; i++) average += zones[i];
	average /= 5;

	/* If the critical zones are stronger than the noise, we are in range */
	if(((zones[1] - average) > 10) && ((zones[2] - average) > 10)) inRange = true;

	/* When we are in range and the critical zones are nearly equal (or we have overshot) we are at the beacon */
	if(inRange && ((zones[1] - zones[2]) > -15)) atBeacon = true;

	return atBeacon;
}
