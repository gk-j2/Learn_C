#include <stdio.h>
#include <stdlib.h>
//-------- Scrambler ----------------------------------
int *scramble(int *bitsIn, int numOfBits) {
	int *bitsOut, i;
	
	bitsOut = (int *)malloc(sizeof(int) * numOfBits);
    for (i = 0; i < numOfBits; ++i) {
        if (i < 4)
			bitsOut[i] = bitsIn[i];
        else if (i < 7)
			bitsOut[i] = bitsIn[i]^bitsOut[i-4];
        else
			bitsOut[i] = bitsIn[i]^bitsOut[i-4]^bitsOut[i-7];
    }
	free(bitsIn);	
	return bitsOut;
}
//------- Rotation ------------------------------------
int *rotation(int *bitsIn, int numOfBits) {
	int *bitsOut, i;

	bitsOut = (int *)malloc(sizeof(int) * numOfBits);
	for (i = 0; i < numOfBits/2; i++) {
		bitsOut[i] = bitsIn[i+i+1];
		bitsOut[i+4] = bitsIn[i+i];
	}
	free(bitsIn);
	return bitsOut;
}
//------- fi_i ----------------------------------------
double *fi_i(int *bitsIn, int numOfBits) {
	double *phase;
	int i, j;

	phase = (double *)malloc(sizeof(double) * (numOfBits / 2));
	for (i = 0, j = 0; i < numOfBits; i+=2, j++) {
		if (bitsIn[i] == 0 && bitsIn[i+1] == 0 && i % 4 == 0)
			phase[j] = 0;
		else if (bitsIn[i] == 0 && bitsIn[i+1] == 1 && i % 8 == 0)
			phase[j] = 3.14 / 2;
		else if (bitsIn[i] == 1 && bitsIn[i+1] == 0 && i % 8 == 0)
			phase[j] = -3.14 / 2;
		else if (bitsIn[i] == 1 && bitsIn[i+1] == 1 && i % 8 == 0)
			phase[j] = 3.14;
		else if (bitsIn[i] == 1 && bitsIn[i+1] == 1)
			phase[j] = -3.14/2;
		else if (bitsIn[i] == 0 && bitsIn[i+1] == 0)
			phase[j] = 0;
		else if (bitsIn[i] == 0 && bitsIn[i+1] == 1)
			phase[j] = 3.14 / 2;
		else if (bitsIn[i] == 1 && bitsIn[i+1] == 0)
			phase[j] = 3.14;
	}
	return phase;
}
//------- QPSK-CCK -----------------------------------------
/*
 1 == 0
-1 == pi
 2 == j
-2 == -j
*/
double *QPSK_CCK(double *phase, int numOfBits) {
	double *qpsk_cck, a[8];
	int i, j;

	qpsk_cck = (double *)malloc(sizeof(double) * numOfBits);
	for (i = 0, j = 0; i < numOfBits; i+=8, j+=4) {
		a[0] = phase[j] + phase[j+1] + phase[j+2] + phase[j+3];
		a[1] = phase[j] + phase[j+2] + phase[j+3];
		a[2] = phase[j] + phase[j+1] + phase[j+3];
		a[3] = phase[j] + phase[j+3] + 3.14;
		a[4] = phase[j] + phase[j+1] + phase[j+2];
		a[5] = phase[j] + phase[j+2];
		a[6] = phase[j] + phase[j+1] + 3.14;
		a[7] = phase[j];
		for (int k = 0; k < 8; k++) {
			if (a[k] == 0 || a[k] == 2 * 3.14 || a[k] == 4 * 3.14 || a[k] == -2 * 3.14 || a[k] == -4 * 3.14) qpsk_cck[k+i] = 1;
			else if (a[k] == 3.14 / 2 || a[k] == 5 * 3.14 / 2 || a[k] == -3 * 3.14 / 2 || a[k] == -7 * 3.14 / 2) qpsk_cck[k+i] = 2;
			else if (a[k] == -3.14 / 2 || a[k] == -5 * 3.14 / 2 || a[k] == 3 * 3.14 / 2 || a[k] == 7 * 3.14 / 2) qpsk_cck[k+i] = -2;
			else if (a[k] == 3.14 || a[k] == 3 * 3.14 || a[k] == -3 * 3.14 || a[k] == -3.14) qpsk_cck[k+i] = -1;
		}
	}
	return qpsk_cck;
}
//------- FHSS ----------------------------------------
void FHSS(double *qpsk_cck, int numOfBits) {
	int i, f[8] = {1,3,10,7,12,6,14,5};

	for (i = 0; i < numOfBits; i++) {
		printf("Freq: [f%d]\tPhase:\t[%f].\n", f[i%8], qpsk_cck[i]);
	}
}
//------- Main Function -------------------------------
int main()
{
    int *in, len, *out;
    double *phase, *qpsk_cck;
 
	len = 1;
	in = (int *)malloc(sizeof(int) * 8);
	in[0] = 1;
	in[1] = 0;
	in[2] = 0;
	in[3] = 1;
	in[4] = 1;
	in[5] = 0;
	in[6] = 0;
	in[7] = 1;
	printf("Bits --> \t\t\t\t\t");
    for (int i = 0; i < len * 8; i++)
		printf("%d", in[i]);
	printf("\n");
	//------------------------------------
	printf("Bits after scrambling --> \t");
	out = scramble(in, 8);
	for (int i = 0; i < 8; i++)
		printf("%d", out[i]);
	printf("\n");
	//------------------------------------
	printf("Bits after rotation --> \t");
	out = rotation(out, 8);
	for (int i = 0; i < 8; i++)
		printf("%d", out[i]);
	printf("\n");
	//------------------------------------
	printf("fi_i --> \t\t\t\t\t");
	phase = fi_i(out,8);
	for (int i = 0; i < 4; i++)
		printf("[%.2f]", phase[i]);
	free(out);
	printf("\n");
	//------------------------------------
	printf("Bits after QPSK CCK --> \t");
	qpsk_cck = QPSK_CCK(phase,8);
	for (int i = 0; i < 8; i++)
		printf("[%.2f]", qpsk_cck[i]);
	free(phase);
	printf("\n");
	//------------------------------------
	printf("Bits after FHSS --> \n");
	FHSS(qpsk_cck, 8);
	printf("\n");
	free(qpsk_cck);
	return 0;
}