#include "hitechnic-accelerometer.h"

int X = 0;

int Y = 0;

int Z = 0;


task Accel_Read()

{

while(1 == 1)

{

HTACreadAllAxes(accel, X, Y, Z);



nxtDisplayBigTextLine(5, "%d", X);

wait1Msec(5);

}



}
