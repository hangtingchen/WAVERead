#pragma once
#ifndef _HMATH_H_
#define _HMATH_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include<stdio.h>
//#include"hmodel.h"
#define bool int
typedef double logdouble;
typedef void* Ptr;
typedef double* Vector;
typedef double** Matrix;
typedef int* IntVec;
typedef int** IntMat;
#define pi 3.1415926

typedef Vector SVector;
typedef Matrix STriMat;
typedef Matrix SMatrix;
typedef struct {
	Vector real;
	Vector imag;
	int N;
}XFFT;

void InitXFFT(XFFT* xfftP, int N);
void ShowXFFT(XFFT xf);
void ShowXFFTE(XFFT xf);
void FreeXFFT(XFFT* xfftP);
int XFFTSize(XFFT x);
void XFFTToVector(XFFT xf, Vector* vp, bool power2Flag);
void VectorToXFFT(XFFT* xfp, Vector v);

IntVec CreateIntVec(int n);
void FreeIntVec(IntVec v);
void ShowIntVec(IntVec v);
void WriteIntVec(FILE* f, IntVec v);

IntMat CreateIntMat(int nrows, int ncols);
void FreeIntMat(IntMat m);

Vector CreateVector(int n);
int VectorSize(Vector v);
void ShowVector(Vector v);
void ShowVectorE(Vector v);
void FreeVector(Vector v);
double FindMax(Vector v);
int FindMaxIndex(Vector v);

Vector CreateSVector(int n);
int SVectorSize(SVector v);
void ShowSVector(SVector v);
void FreeSVector(SVector v);

Matrix CreateMatrix(int nrows, int ncols);
int NumRows(Matrix m);
int NumCols(Matrix m);
void ShowMatrix(Matrix m);
void FreeMatrix(Matrix m);

SMatrix CreateSMatrix(int nrows, int ncols);
int NumRowsS(SMatrix m);
int NumColsS(SMatrix m);
void ShowSMatrix(SMatrix m);
void FreeSMatrix(SMatrix m);

Matrix CreateSTriMat(int size);
int STriMatSize(STriMat m);
void ShowSTriMat(STriMat m);
void FreeSTriMat(STriMat m);

Ptr GetHook(Ptr m);
void SetHook(Ptr m, Ptr ptr);
void SetUse(Ptr m, int n);

void ZeroVector(Vector v);
void ZeroSVector(SVector v);
void ZeroMatrix(Matrix m);
void ZeroIntMat(IntMat m);
void ZeroSTriMat(STriMat m);
void ZeroIntVec(IntVec v);
void CopyVector(Vector v1, Vector v2);
void CopyVector2(Vector v1, IntVec ind1, Vector v2, IntVec ind2);
void CopyMatrix(Matrix m1, Matrix m2);
void CopySTriMat(STriMat m1, STriMat m2);
void CopyMatToTri(Matrix m1, STriMat m2);

void WriteMatrix(FILE* f,Matrix m);
void WriteIntMat(FILE* f, IntMat m);
void WriteSTriMat(FILE* f, STriMat m);
void WriteSVector(FILE* f,SVector v);
void WriteVectorE(FILE* f, Vector v);

void LoadMatrix(FILE* f, Matrix m);
void LoadStriMat(FILE*f, STriMat m);
void LoadSVector(FILE* f, SVector v);
void LoadSVectorE(FILE* f, SVector v);


bool Choleski(STriMat A, Matrix L);
void MSolve(Matrix L, int i, Vector x, Vector y);
logdouble CovInvert(STriMat c, STriMat invc);
logdouble CovDet(STriMat c);
int mod(int a, int b);
void reshape(Matrix* mp, Vector v, int r, int c,int dim);


#ifdef __cplusplus
}
#endif // __cplusplus

#endif