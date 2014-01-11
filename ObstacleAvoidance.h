

int currentPathLocation = 0;
int currentPathInt = 0;
int currentPathArray[10][2];
bool hadCollisionAtStart = true;

void determinePath();

void determinePath(){
	//Decides which of the preprogrammed paths to use to reach our destination
	if (hadCollisionAtStart == false){ // if its our first time calling this function, and we didn't crash
		//set the path to the main path
		hadCollisionAtStart = true; // Change variable to prevent it from running more than once
		currentPathInt = 0;
		currentPathLocation = 0;
		memcpy(currentPathArray, corePath, sizeof(corePath));
		PlaySound(soundBeepBeep);
		return;
	}else{// else calculate the path to follow based on information given
		if (currentPathInt ==  0){
			if (currentPathLocation == 0){

			}
		}
	}
}
