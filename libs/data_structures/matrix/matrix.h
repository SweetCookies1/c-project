#include <stdbool.h>

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

matrix getMemMatrix(int nRows, int nCols);

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCows);

void freeMemMatrix(matrix m);

void freeMemMatrices(matrix *ms, int nMatrices);

void inputMatrix(matrix m);

void inputMatrices(matrix *ms, int nMatrices);

void outputMatrix(matrix m);

void outputMatrices(matrix *ms, int nMatrices);

bool isSquareMatrix(matrix m);

bool twoMatricesEqual(matrix m1, matrix m2);

matrix createMatrixFromArray(const int *a, int nRows, int nCols);

matrix *createMatrixArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols);

#endif //LABA5B_MATRIX_H
