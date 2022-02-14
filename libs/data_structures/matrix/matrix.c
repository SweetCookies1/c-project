#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include "matrix.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int *getColumn(matrix m, int j) {
    int *result = (int *) malloc(m.nRows * sizeof(int));
    for (int i = 0; i < m.nRows; i++)
        result[i] = m.values[i][j];

    return result;
}

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCows) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCows);
    return ms;
}

void freeMemMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        free(m.values[i]);
    free(m.values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(ms[i]);
    free(ms);
}

void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            scanf("%d", &m.values[i][j]);
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        inputMatrix(ms[i]);
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++) {
            printf("%d", m.values[i][j]);
            printf("\n");
        }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        outputMatrix(ms[i]);
}

bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

void swapRows(matrix m, int i1, int i2) {
    if (i1 == i2)
        return;
    swap(m.values[i1], m.values[i2]);
}

void swapColumns(matrix m, int j1, int j2) {
    if (j1 == j2)
        return;
    for (int i = 0; i < m.nRows; i++)
        swap(&m.values[i][j1 - 1], &m.values[i][j2 - 1]);
}

bool twoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;
    for (int i = 0; i < m1.nRows; i++)
        for (int j = 0; j < m1.nCols; j++)
            if (m1.values[i][j] != m2.values[i][j])
                return false;
    return true;
}

bool isEMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if ((i == j && m.values[i][j] != 1) || (i != j && m.values[i][j] != 0))
                return false;
    return true;
}

bool isSymmetricMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] != m.values[j][i])
                return false;
    return true;
}

position getMinValuePos(matrix m) {
    position minValuePos = {0, 0};
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++) {
            position curPos = {i, j};
            if (m.values[curPos.rowIndex][curPos.colIndex] < m.values[minValuePos.rowIndex][minValuePos.colIndex])
                minValuePos = curPos;
        }
    return minValuePos;

}

position getMaxValuePos(matrix m) {
    position maxValuePos = {0, 0};
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++) {
            position curPos = {i, j};
            if (m.values[curPos.rowIndex][curPos.colIndex] > m.values[maxValuePos.rowIndex][maxValuePos.colIndex])
                maxValuePos = curPos;
        }
    return maxValuePos;
}

void transposeSquareMatrix(matrix m) {
    assert(isSquareMatrix(m));
    for (int i = 0; i < m.nRows; i++)
        for (int j = i + 1; j < m.nCols; j++)
            if (i != j)
                swap(&m.values[i][j], &m.values[j][i]);

}

matrix createMatrixFromArray(const int *a, int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);
    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];
    return m;
}

matrix *createMatrixArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];
    return ms;

}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int *resultsCriteria = (int *) malloc(m.nRows * sizeof(int));
    for (int i = 0; i < m.nRows; i++)
        resultsCriteria[i] = criteria(m.values[i], m.nCols);
    for (int i = 1; i < m.nRows; i++) {
        int t = i;
        while (resultsCriteria[t] < resultsCriteria[t - 1] && t > 0) {
            swap(&resultsCriteria[t], &resultsCriteria[t - 1]);
            swapRows(m, t, t - 1);
            t--;
        }
    }
    free(resultsCriteria);
}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int *resultsCriteria = (int *) malloc(m.nCols * sizeof(int));
    for (int i = 0; i < m.nCols; i++) {
        int *currentColumn = getColumn(m, i);
        resultsCriteria[i] = criteria(currentColumn, m.nRows);
        free(currentColumn);
    }
    for (int i = 1; i < m.nCols; i++) {
        int t = i;
        while (resultsCriteria[t] < resultsCriteria[t - 1] && t > 0) {
            swap(&resultsCriteria[t], &resultsCriteria[t - 1]);
            swapColumns(m, t, t - 1);
            t--;
        }
    }
    free(resultsCriteria);
}

void swapColsMinAndMaxValue(matrix m) {
    swapRows(m, getMinValuePos(m).rowIndex + 1, getMaxValuePos(m).rowIndex + 1);
}

matrix mulMatrices(matrix m1, matrix m2) {
    matrix mulMatrix = getMemMatrix(m1.nRows, m2.nCols);
    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m2.nCols; j++) {
            mulMatrix.values[i][j] = 0;
            for (int k = 0; k < m2.nRows; k++) {
                mulMatrix.values[i][j] += m1.values[i][j] * m2.values[k][j];
            }
        }
    }
    return (matrix) {mulMatrix.values, m1.nRows, m2.nCols};
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (!isSymmetricMatrix(*m))
        return;
    mulMatrices(*m, *m);
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    if (isEMatrix(mulMatrices(m1, m2)))
        return true;
    return false;
}

