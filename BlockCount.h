#include "drivers/hitechnic-superpro.h"
ubyte outvalue;
float analog0 = 0;
int analog1 = 0;
int analog2 = 0;
int analog3 = 0;
int bit = 0;
int blockCount = 0;
task CountBlocks()
{
	//HTSPBsetupIO(HTSPB, 0x4F);
	HTSPBsetupIO(HTSPB, 0x3F);
	wait10Msec(50);
	int startValue = HTSPBreadADC(HTSPB,0,10);
	while(true){
		analog0 = HTSPBreadADC(HTSPB,0,10);
		if (abs(analog0 - startValue) > 40 && time1[T1] > 1000){
			blockCount++;
			time1[T1] = 0;
		}
		if (blockCount == 0){
			HTSPBwriteIO(HTSPB, 0x00);
		}else if (blockCount == 1){
			HTSPBwriteIO(HTSPB, 0x01);
		}else if (blockCount == 2){
			HTSPBwriteIO(HTSPB, 0x03);
		}else if (blockCount == 3){
			HTSPBwriteIO(HTSPB, 0x07);
		}else if (blockCount == 4){
			HTSPBwriteIO(HTSPB, 0x0F);
		}
		nxtDisplayCenteredBigTextLine(3, "%d", blockCount);
	}
}
