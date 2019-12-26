#include <stdio.h>
#include <stdlib.h>
//-------- Scrambler ----------------------------------
int		*scramble(int *bitsIn, int numOfBits) {
	int	*bitsOut, i;
	
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
//------- PBCC Y_0 ----------------------------------
int		*pbcc_y0(int *bitsIn, int numOfBits) {
	int	*bitsOut, i;
	
	bitsOut = (int *)malloc(sizeof(int) * numOfBits);
    for (i = 0; i < numOfBits; ++i) {
        if (i == 0)
			bitsOut[i] = bitsIn[i];
        else if (i < 3)
			bitsOut[i] = bitsIn[i]^bitsIn[i-1];
        else if (i == 3)
			bitsOut[i] = bitsIn[i]^bitsIn[i-1]^bitsIn[i-3];
        else if (i < 6)
			bitsOut[i] = bitsIn[i]^bitsIn[i-1]^bitsIn[i-3]^bitsIn[i-4];
        else if (i < 8)
			bitsOut[i] = bitsIn[i]^bitsIn[i-1]^bitsIn[i-3]^bitsIn[i-4]^bitsIn[i-6];
    }
	return bitsOut;
}
//------- PBCC Y_1 ----------------------------------
int		*pbcc_y1(int *bitsIn, int numOfBits) {
	int	*bitsOut, i;
	
	bitsOut = (int *)malloc(sizeof(int) * numOfBits);
    for (i = 0; i < numOfBits; ++i) {
        if (i < 2)
			bitsOut[i] = bitsIn[i];
        else if (i == 2)
			bitsOut[i] = bitsIn[i]^bitsIn[i-2];
        else if (i == 3)
			bitsOut[i] = bitsIn[i]^bitsIn[i-2]^bitsIn[i-3];
        else if (i < 6)
			bitsOut[i] = bitsIn[i]^bitsIn[i-2]^bitsIn[i-3]^bitsIn[i-4];
        else if (i < 8)
			bitsOut[i] = bitsIn[i]^bitsIn[i-2]^bitsIn[i-3]^bitsIn[i-4]^bitsIn[i-6];
    }
	return bitsOut;
}
//------- Punctir 2/3 ---------------------------------
int		*punctir_2_3(int *y_0, int *y_1, int numOfBits) {
	int	*bitsOut, i, j = 0;

	bitsOut = (int *)malloc(sizeof(int) * (numOfBits * 3 / 2));
	for (i = 0; i < numOfBits; i++) {
		bitsOut[j] = y_0[i];
		j++;
		if (i % 2 == 0) {
			bitsOut[j] = y_1[i];
			j++;
		}
	}
	return bitsOut;
}
//------- Rotation ------------------------------------
int		*rotation(int *bitsIn, int numOfBits) {
	int	*bitsOut, i;

	bitsOut = (int *)malloc(sizeof(int) * numOfBits);
	for (i = 0; i < numOfBits; i+=12) {
		bitsOut[i] = bitsIn[i+1]; 
		bitsOut[i+1] = bitsIn[i+3];
		bitsOut[i+2] = bitsIn[i];
		bitsOut[i+3] = bitsIn[i+5];
		bitsOut[i+4] = bitsIn[i+7];
		bitsOut[i+5] = bitsIn[i+9];
		bitsOut[i+6] = bitsIn[i+11];
		bitsOut[i+7] = bitsIn[i+2];
		bitsOut[i+8] = bitsIn[i+4];
		bitsOut[i+9] = bitsIn[i+6];
		bitsOut[i+10] = bitsIn[i+8];
		bitsOut[i+11] = bitsIn[i+10];
	}
	free(bitsIn);
	return bitsOut;
}
//------- QAM-8 ---------------------------------------
/*
| Bit | Ampl  |  Phi |
|-----|-------|------|
| 000 | 0.765 | -135 |
|-----|-------|------|
| 001 | 1.848 | -135 |
|-----|-------|------|
| 010 | 0.765 | -45  |
|-----|-------|------|
| 011 | 1.848 | -45  |
|-----|-------|------|
| 100 | 0.765 | +135 |
|-----|-------|------|
| 101 | 1.848 | +135 |
|-----|-------|------|
| 110 | 0.765 | +45  |
|-----|-------|------|
| 111 | 1.848 | +45  |
|-----|-------|------|

*/
double	*qam8(int *bitsIn, int numOfBits) {
	int		i, j, k;
	double	*qam_8;

	qam_8 = (double *)malloc(sizeof(double) * (numOfBits / 3 * 2));
	for (k = 0, i = 0, j = numOfBits / 3; k < numOfBits; k+=3, i++, j++) {
		if (bitsIn[k] == 0 && bitsIn[k+1] == 0 && bitsIn[k+2] == 0) {//0
			qam_8[i] = 0.765;
			qam_8[j] = -3.14 * 3 / 4; 
		}
		else if (bitsIn[k] == 0 && bitsIn[k+1] == 0 && bitsIn[k+2] == 1) {//1
			qam_8[i] = 1.848;
			qam_8[j] = -3.14 * 3 / 4; 
		}
		else if (bitsIn[k] == 0 && bitsIn[k+1] == 1 && bitsIn[k+2] == 0) {//2
			qam_8[i] = 0.765;
			qam_8[j] = -3.14 / 4; 
		}
		else if (bitsIn[k] == 0 && bitsIn[k+1] == 1 && bitsIn[k+2] == 1) {//3
			qam_8[i] = 1.848;
			qam_8[j] = -3.14 / 4; 
		}
		else if (bitsIn[k] == 1 && bitsIn[k+1] == 0 && bitsIn[k+2] == 0) {//4
			qam_8[i] = 0.765;
			qam_8[j] = 3.14 * 3 / 4; 
		}
		else if (bitsIn[k] == 1 && bitsIn[k+1] == 0 && bitsIn[k+2] == 1) {//5
			qam_8[i] = 1.848;
			qam_8[j] = 3.14 * 3 / 4; 
		}
		else if (bitsIn[k] == 1 && bitsIn[k+1] == 1 && bitsIn[k+2] == 0) {//6
			qam_8[i] = 0.765;
			qam_8[j] = 3.14 / 4; 
		}
		else if (bitsIn[k] == 1 && bitsIn[k+1] == 1 && bitsIn[k+2] == 1) {//7
			qam_8[i] = 1.848;
			qam_8[j] = 3.14 / 4; 
		}
	}
	free(bitsIn);
	return qam_8;
}
//------- Main Function -------------------------------
int		main()
{
    int		*in, len, *out, *y_0, *y_1;
    double	*phase, *qpsk_cck, *qam_8;
 
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
	printf("Bits Y_0 --> \t\t\t\t");
	y_0 = pbcc_y0(out, 8);
	for (int i = 0; i < 8; i++)
		printf("%d", y_0[i]);
	printf("\n");
	//------------------------------------
	printf("Bits Y_1 --> \t\t\t\t");
	y_1 = pbcc_y1(out, 8);
	for (int i = 0; i < 8; i++)
		printf("%d", y_1[i]);
	printf("\n");
	//------------------------------------
	printf("Bits after Punctir 2/3 --> \t");
	free(out);
	out = punctir_2_3(y_0, y_1, 8);
	for (int i = 0; i < 12; i++)
		printf("%d", out[i]);
	free(y_0);
	free(y_1);
	printf("\n");
	//------------------------------------
	printf("Bits after Rotation --> \t");
	out = rotation(out, 12);
	for (int i = 0; i < 12; i++)
		printf("%d", out[i]);
	printf("\n");
	//------------------------------------
	printf("Bits after QAM-8 --> \t\t");
	qam_8 = qam8(out, 12);
	for (int i = 0; i < 12 / 3 * 2 ; i++) {
		if (i == 12 / 3) printf("\n\t\t\t\t\t\t\t");
		printf("[%.4f]", qam_8[i]);
	}
	free(qam_8);
	printf("\n");
	free(out);
	return 0;
}