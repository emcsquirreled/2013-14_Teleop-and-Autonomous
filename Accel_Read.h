

int x = 0;

int y = 0;

int Z = 0;

task Accel_Read()

{

while(1 == 1)

{

HTACreadAllAxes(accel, x, y, Z);



nxtDisplayBigTextLine(5, "%d", x);

wait1Msec(5);

}



}
