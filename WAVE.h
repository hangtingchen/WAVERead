#pragma once
#ifndef _WAVE_H_
#define _WAVE_H_

#ifdef _cplusplus
extern "C" {
#endif // _cplusplus

#ifdef _MSC_VER  
typedef __int32 int32_t; 
typedef unsigned __int32 uint32_t; 
typedef __int64 int64_t; 
typedef unsigned __int64 uint64_t;  
typedef unsigned __int16 uint16_t;
#else 
#include <stdint.h> 
#endif


#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "hmath.h"

typedef struct {
	char ckID[4];
	uint32_t cksize;
	char WAVEID[4];
}RIFF_t;

typedef struct {
	char ckID[4];
	uint32_t cksize;
	uint16_t wFormatTag;
	uint16_t nChannels;
	uint32_t nSamplesPerSec;
	uint32_t nAvgBytesPerSec;
	uint16_t nBlockAlign;
	uint16_t wBitsPerSample;
}fmt_t;

typedef struct {
	int numChannels;
	int numSamples;
	int sampleRate;
	int sampleLengthInByte;
	int containerLengthInByte;
}WAVEParams_t;

typedef struct {
	char ckID[4];
	uint32_t cksize;
	int** data;
}DATA_t;

typedef struct {
	RIFF_t RIFF;
	fmt_t fmt;
	DATA_t DATA;
	WAVEParams_t WAVEParams;
	int myEndian;
}WAVE_t;

long int readWAVE(FILE* f, size_t sizeInByte, int EndianFlag);
WAVE_t initWAVE_t();
void loadWAVEFile(WAVE_t* w, FILE* f);
int WAVEParamsCheck(WAVEParams_t w1, WAVEParams_t w2);
void print_WAVE(WAVE_t w);
void free_WAVE(WAVE_t* w);

#ifdef _cplusplus
}
#endif // _cplusplus

#endif // !_WAVE_H_
