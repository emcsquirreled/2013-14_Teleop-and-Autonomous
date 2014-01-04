//---------VARIABLES--------//

//Collision.h//
int Movement = 0;
int CollisionThreshold = -75; //set to threshold --- default is -75

//Direction.h//
float CurrentHeading = 1;

//distance.h//
float distance = 0;

//Position.h//
float X = 4;  //11.7475 start position
float Y = 3.1; //7.9375 start position



//---------GETS AND WRITES--------//

//Collision.h//
int getMovement() {return(Movement);}
void writeMovement(int m) {Movement = m;}

int getCollisionThreshold() {return(CollisionThreshold);}
void writeCollisionThreshold(int s) {CollisionThreshold = s;}

//Direction.h//
int getCurrentHeading() {return(CurrentHeading);}
void writeCurrentHeading(float c) {CurrentHeading = c;}

//distance.h
int getDistance() {return(distance);}
void writeDistance(float d) {distance = d;}

//Position.h//
int getX() {return(X);}
void writeX(float x) {X = x;}

int getY() {return(Y);}
void writeY(float y) {Y = y;}
