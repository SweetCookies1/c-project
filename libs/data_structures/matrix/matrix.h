#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdint.h>
#include <limits.h>
#include <string.h>
#include <memory.h>
#include <math.h>


#ifndef LABA5B_MATRIX_H
#define LABA5B_MATRIX_H

typedef struct matrix {
    int ** values;
    int nRows;
    int nCols;
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

int getSum(int *a, int n);

float getDistance(int *a, int n);

int getMin(int *a, int n);

int getMax(int *a, int n);

int countNUnique(long long *a, int n);

bool isUnique(long long *a, int n);

void swap(int *a, int *b);

void swapf(float *a, float *b);

matrix mulMatrices(matrix m1, matrix m2);

matrix getMemMatrix(int nRows, int nCols);

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCows);

void freeMemMatrix(matrix m);

matrix getMemMatrix1(int nRows, int nCols);

void freeMemMatrices(matrix *ms, int nMatrices);

void inputMatrix(matrix m);

void inputMatrices(matrix *ms, int nMatrices);

void outputMatrix(matrix m);

void outputMatrices(matrix *ms, int nMatrices);

void swapRows(matrix m, int i1, int i2);

void swapColumns(matrix m, int j1, int j2);

bool isSquareMatrix(matrix m);

bool twoMatricesEqual(matrix m1, matrix m2);

bool isEMatrix(matrix m);

bool isSymmetricMatrix(matrix m);

position getMinValuePos(matrix m);

position getMaxValuePos(matrix m);

matrix createMatrixFromArray(const int *a, int nRows, int nCols);

matrix *createMatrixArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols);

void transposeSquareMatrix(matrix m);

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int));

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int));

void swapColsMinAndMaxValue(matrix m);

void sortColsByMinElement(matrix m);

void sortRowsByMaxElement(matrix m);

void getSquareOfMatrixIfSymmetric(matrix *m);

bool isMutuallyInverseMatrices(matrix m1, matrix m2);

matrix mulMatrices(matrix m1, matrix m2);

void transposeIfMatrixHasNotEqualSumOfRows(matrix *m);

int getMinInArea(matrix m);

int findSumMaxesOfPseudoDiagonal(matrix m);

void sortByDistances(matrix m);

int countEqClassesByRowsSum(matrix m);

int getNSpecialElement(matrix m);

void swapPenultimateRow(matrix m);

int countValues(const int *a, int n, int value);

int countZeroRows(matrix m);

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix);

bool isNonDescendingSorted(int *a, int n);

bool hasAllNonDescendingRows(matrix m);

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix);

int normMaxInMatrix(matrix m);

void printMatrixWithMinNorm(matrix *ms, int nMatrix);

int getScalarProduct(int *a, int *b, int n);

int getScalarProductRowAndCol(matrix m, int i, int j);

int getSpecialScalarProduct(matrix m, int n);

#endif //LABA5B_MATRIX_H
