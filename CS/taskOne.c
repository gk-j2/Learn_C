#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//-------- Input String --------------------------------
void *inputData(int *len) {
	char *str, c;

	printf("Enter the string:\n");
	str = (char	*)malloc(sizeof(char) * 32);
	scanf("%c", &c);
	while(c != '\n' && *len != 31) {
		str[*len] = c;
		(*len)++;
		scanf("%c", &c);
	}
	str[*len] = '\0';
	//write(1,"end str\n", 8);
	return str;
}
//------- String To Bits -------------------------------
int *str2bits(char *str, int len) {
	int *in;
	int shift, i, j;

	//write(1, "start STB\n", 10);
	in = (int *)malloc(sizeof(int) * len * 8);
	shift = 0;

    for (i = 0; i < len; ++i ) {
        for (j = 7; j > -1; j--) {
            in[shift+7-j] = ((str[i] >> j) & 1);
            printf("%d", in[shift+7-j]);
        }        
        shift+=8;
    }
	//write(1, "end STB\n", 8);
	return in;
}
//-------- 4 Bits / 5 Bits ----------------------------
int *forBitsFiveBits(int *bitsIn, int len) {
	int *bitsOut, i, j, k;
	
	//write(1, "start 4B/5B\n", 12);
	bitsOut = (int *)malloc(sizeof(int) * (len * 8 + len * 2));
	for(k = 0, i = 0, j = 0; k < len * 2;k++, i+=4, j+=5) {
		if (bitsIn[i] == 0 && bitsIn[i+1] == 0 && bitsIn[i+2] == 0 && bitsIn[i+3] == 0){//0
			bitsOut[j] = 1;
			bitsOut[j+1] = 1;
			bitsOut[j+2] = 1;
			bitsOut[j+3] = 1;
			bitsOut[j+4] = 0;
		}
		else if (bitsIn[i] == 0 && bitsIn[i+1] == 0 && bitsIn[i+2] == 0 && bitsIn[i+3] == 1){//1
			bitsOut[j] = 0;
			bitsOut[j+1] = 1;
			bitsOut[j+2] = 0;
			bitsOut[j+3] = 0;
			bitsOut[j+4] = 1;
		}
		else if (bitsIn[i] == 0 && bitsIn[i+1] == 0 && bitsIn[i+2] == 1 && bitsIn[i+3] == 0){//2
			bitsOut[j] = 1;
			bitsOut[j+1] = 0;
			bitsOut[j+2] = 1;
			bitsOut[j+3] = 0;
			bitsOut[j+4] = 0;
		}
		else if (bitsIn[i] == 0 && bitsIn[i+1] == 0 && bitsIn[i+2] == 1 && bitsIn[i+3] == 1){//3
			bitsOut[j] = 1;
			bitsOut[j+1] = 0;
			bitsOut[j+2] = 1;
			bitsOut[j+3] = 0;
			bitsOut[j+4] = 1;
		}
		else if (bitsIn[i] == 0 && bitsIn[i+1] == 1 && bitsIn[i+2] == 0 && bitsIn[i+3] == 0){//4
			bitsOut[j] = 0;
			bitsOut[j+1] = 1;
			bitsOut[j+2] = 0;
			bitsOut[j+3] = 1;
			bitsOut[j+4] = 0;
		}
		else if (bitsIn[i] == 0 && bitsIn[i+1] == 1 && bitsIn[i+2] == 0 && bitsIn[i+3] == 1){//5
			bitsOut[j] = 0;
			bitsOut[j+1] = 1;
			bitsOut[j+2] = 0;
			bitsOut[j+3] = 1;
			bitsOut[j+4] = 1;
		}
		else if (bitsIn[i] == 0 && bitsIn[i+1] == 1 && bitsIn[i+2] == 1 && bitsIn[i+3] == 0){//6
			bitsOut[j] = 0;
			bitsOut[j+1] = 1;
			bitsOut[j+2] = 1;
			bitsOut[j+3] = 1;
			bitsOut[j+4] = 0;
		}
		else if (bitsIn[i] == 0 && bitsIn[i+1] == 1 && bitsIn[i+2] == 1 && bitsIn[i+3] == 1){//7
			bitsOut[j] = 0;
			bitsOut[j+1] = 1;
			bitsOut[j+2] = 1;
			bitsOut[j+3] = 1;
			bitsOut[j+4] = 1;
		}
		else if (bitsIn[i] == 1 && bitsIn[i+1] == 0 && bitsIn[i+2] == 0 && bitsIn[i+3] == 0){//8
			bitsOut[j] = 1;
			bitsOut[j+1] = 0;
			bitsOut[j+2] = 0;
			bitsOut[j+3] = 1;
			bitsOut[j+4] = 0;
		}
		else if (bitsIn[i] == 1 && bitsIn[i+1] == 0 && bitsIn[i+2] == 0 && bitsIn[i+3] == 1){//9
			bitsOut[j] = 1;
			bitsOut[j+1] = 0;
			bitsOut[j+2] = 0;
			bitsOut[j+3] = 1;
			bitsOut[j+4] = 1;
		}
		else if (bitsIn[i] == 1 && bitsIn[i+1] == 0 && bitsIn[i+2] == 1 && bitsIn[i+3] == 0){//10
			bitsOut[j] = 1;
			bitsOut[j+1] = 0;
			bitsOut[j+2] = 1;
			bitsOut[j+3] = 1;
			bitsOut[j+4] = 0;
		}
		else if (bitsIn[i] == 1 && bitsIn[i+1] == 0 && bitsIn[i+2] == 1 && bitsIn[i+3] == 1){//11
			bitsOut[j] = 1;
			bitsOut[j+1] = 0;
			bitsOut[j+2] = 1;
			bitsOut[j+3] = 1;
			bitsOut[j+4] = 1;
		}
		else if (bitsIn[i] == 1 && bitsIn[i+1] == 1 && bitsIn[i+2] == 0 && bitsIn[i+3] == 0){//12
			bitsOut[j] = 1;
			bitsOut[j+1] = 1;
			bitsOut[j+2] = 0;
			bitsOut[j+3] = 1;
			bitsOut[j+4] = 0;
		}
		else if (bitsIn[i] == 1 && bitsIn[i+1] == 1 && bitsIn[i+2] == 0 && bitsIn[i+3] == 1){//13
			bitsOut[j] = 1;
			bitsOut[j+1] = 1;
			bitsOut[j+2] = 0;
			bitsOut[j+3] = 1;
			bitsOut[j+4] = 1;
		}
		else if (bitsIn[i] == 1 && bitsIn[i+1] == 1 && bitsIn[i+2] == 1 && bitsIn[i+3] == 0){//14
			bitsOut[j] = 1;
			bitsOut[j+1] = 1;
			bitsOut[j+2] = 1;
			bitsOut[j+3] = 0;
			bitsOut[j+4] = 0;
		}
		else {//15
			bitsOut[j] = 1;
			bitsOut[j+1] = 1;
			bitsOut[j+2] = 1;
			bitsOut[j+3] = 0;
			bitsOut[j+4] = 1;
		}
	}
    free(bitsIn);
	//write(1, "end 4B/5B\n", 10);
	return bitsOut;
}
//-------- Scrambler ----------------------------------
int *scramble(int *bitsIn, int numOfBits) {
	int *bitsOut, i;
	
//	write(1, "start scram\n", 12);
	bitsOut = (int *)malloc(sizeof(int) * numOfBits);
    for (i = 0; i < numOfBits; ++i) {
        if (i < 3)
			bitsOut[i] = bitsIn[i];
        else if (i < 5)
			bitsOut[i] = bitsIn[i]^bitsOut[i-3];
        else
			bitsOut[i] = bitsIn[i]^bitsOut[i-3]^bitsOut[i-5];
    }
	free(bitsIn);	
	//write(1, "end scram\n", 10);
	return bitsOut;
}
//------- NRZI ----------------------------------------
int *nrzi(int *bitsIn, int numOfBits) {
	int *bitsOut, i, code;
	
	//write(1, "start nrzi\n", 11);
	bitsOut = (int *)malloc(sizeof(int) * numOfBits);
	if(bitsIn[0] == 0)
		code = 0;
	else
		code = 1;
	for (i = 0; i < numOfBits; i++) {
		bitsOut[i] = code;
		printf("%d", bitsOut[i]);
		if(bitsIn[i+1] == 0)
			code = code;
		else if(bitsIn[i+1] == 1 && code == 0)
			code = 1;
		else
			code = 0;
	}
	bitsOut[i] = code;
	free(bitsIn);
	//write(1, "end nrzi\n", 9);
	return bitsOut;
}
//------- MLT3 ----------------------------------------
int *mlt3(int *bitsIn, int numOfBits) {
	int *bitsOut, i, state, mem;

	//write(1, "start mlt3\n", 11);
	bitsOut = (int *)malloc(sizeof(int) * numOfBits);
	state = 0;
    mem = -1;
    bitsOut[0] = state;
    printf("%d", bitsOut[0]);
	for (i = 1; i < numOfBits; i++) {
       if(bitsIn[i] == 0)
         bitsOut[i] = state;
       else if(state == 1 || state == -1)
         state = 0;
       else if(mem == -1) {
         state = 1;
         mem = 1;
       }
       else if (mem == 1) {
         state = -1;
         mem = -1;
       }
        bitsOut[i] = state;
		printf("%d", bitsOut[i]);
      }
	 free(bitsIn);
	//write(1, "end mlt3\n", 9);
	return bitsOut;
}
//------- Main Function -------------------------------
int main()
{
	//char *str;
    int *in;
	int len;
    int *out;
 
	len = 1;
	in = (int *)malloc(sizeof(int) * 8);
	in[0] = 0;
	in[1] = 0;
	in[2] = 0;
	in[3] = 1;
	in[4] = 1;
	in[5] = 0;
	in[6] = 0;
	in[7] = 1;
	//str = inputData(&len);
	//in = str2bits(str, len);
	printf("Bits --> \t\t\t\t\t");
    for (int i = 0; i < len * 8; i++)
		printf("%d", in[i]);
	printf("\n");
	
	printf("Bits after 4B/5B --> \t\t");
	out = forBitsFiveBits(in, len);
	for (int i = 0; i < len * 8 + len * 2; i++)
		printf("%d", out[i]);
	printf("\n");

	free(in);	
	printf("Bits after scrambling --> \t");
	out = scramble(out, len * 8 + len * 2);
	for (int i = 0; i < len * 8 + len * 2; i++)
		printf("%d", out[i]);
	printf("\n");
	
	printf("Bits after NRZI --> \t\t");
	out = nrzi(out, len * 8 + len * 2);
	printf("\n");

	printf("Bits after MLT3 --> \t\t");
	out = mlt3(out, len * 8 + len * 2);
	printf("\n");

	//free(str);
	free(out);
	return 0;
} 