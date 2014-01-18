

int x_accel = 0;

int y = 0;

int Z = 0;

task Accel_Read()

{

while(1 == 1)

{

HTACreadAllAxes(accel, x_accel, y, Z);



nxtDisplayBigTextLine(5, "%d", x_accel);

wait1Msec(5);

}



}
