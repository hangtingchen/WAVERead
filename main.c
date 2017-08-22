#include<stdio.h>
#include<stdlib.h>
#include "hmath.h"
#include "WAVE.h"

//this is an example to use WAVE.c
int main() {
	FILE* f2=NULL;FILE* f=NULL;
	//load WAVE file to INTMATRIX
	WAVE_t w = initWAVE_t();
	//be sure to open the WAVE file in mode "rb"
	f = fopen("a001_0_30.wav", "rb");
	loadWAVEFile(&w, f);
	print_WAVE(w);
	fclose(f);
	//write INTMATRIX to the file
	f2 = fopen("matrix1.dat", "w");
	WriteIntMat(f2, w.DATA.data);
	fclose(f2);
	free_WAVE(&w);

	system("pause");
	return 0;
}