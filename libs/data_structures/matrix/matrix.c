#include "matrix.h"

#define IS_NOT_SQUARE_MATRIX throw_exception("matrix is not square")
#define MATRIX_MUL_ERROR throw_exception("first matrix with not equal second matrix height")
#define BAD_ALLOC_CHECK(mem) if(mem == NULL) throw_exception("bad alloc")

static inline void throw_exception(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

int max2(int a, int b) {
    return a > b ? a : b;
}

float getDistance(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i] * a[i];
    return sqrt(sum);
}

int getMin(int *a, int n) {
    int min = a[0];
    for (size_t i = 1; i < n; i++)
        if (min > a[i])
            min = a[i];
    return min;
}

int getMax(int *a, int n) {
    int max = a[0];
    for (size_t i = 1; i < n; i++)
        if (max < a[i])
            max = a[i];
    return max;
}

int getSum(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

int countNUnique(long long *a, int n) {
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            res += (a[i] == a[j]);
    return res;
}

bool isUnique(long long *a, int n) {
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; j++)
            if (a[i] == a[j])
                return true;
    return false;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapf(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

matrix mulMatrices(matrix m1, matrix m2) {
    if (m1.nCols != m2.nRows)
        MATRIX_MUL_ERROR;
    matrix result = getMemMatrix(m1.nRows, m2.nCols);
    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m2.nCols; j++) {
            result.values[i][j] = 0;
            for (int k = 0; k < m1.nCols; k++) {
                result.values[i][j] += m1.values[i][k] * m2.values[k][j];
            }
        }
    }
    return result;
}

/*
matrix getMemMatrix1(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    values[0] = (int *) malloc(sizeof(int) * nCols * nRows);
    for (int i = 1; i < nRows; i++)
        values[i] = &values[0][0] + i * nCols;
    return (matrix) {values, nRows, nCols};
}

void freeMemMatrix1(matrix m) {
        free(m.values[0]);
    free(m.values);
}
*/

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    BAD_ALLOC_CHECK(values);
    for (int i = 0; i < nRows; i++) {
        values[i] = (int *) malloc(sizeof(int) * nCols);
        BAD_ALLOC_CHECK(values[i]);
    }
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCows) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    BAD_ALLOC_CHECK(ms);
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
        for (int j = 0; j < m.nCols; j++)
            printf("%d", m.values[i][j]);
    printf("\n");
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        outputMatrix(ms[i]);
}

void swapRows(matrix m, int i1, int i2) {
    if (i1 == i2)
        return;
    swap((int *) &m.values[i1], (int *) &m.values[i2]);
}

void swapColumns(matrix m, int j1, int j2) {
    if (j1 == j2)
        return;
    for (int i = 0; i < m.nRows; i++)
        swap(&m.values[i][j1], &m.values[i][j2]);
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int *resCriteria = (int *) malloc(m.nRows * sizeof(int));
    BAD_ALLOC_CHECK(resCriteria);

    for (int i = 0; i < m.nRows; i++)
        resCriteria[i] = criteria(m.values[i], m.nCols);

    for (int i = 1; i < m.nRows; i++) {
        int t = i;
        while (resCriteria[t] < resCriteria[t - 1] && t > 0) {
            swap(&resCriteria[t], &resCriteria[t - 1]);
            swapRows(m, t, t - 1);
            t--;
        }
    }
    free(resCriteria);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)) {
    float *resCriteria = (float *) malloc(m.nRows * sizeof(float));
    BAD_ALLOC_CHECK(resCriteria);

    for (int i = 0; i < m.nRows; i++)
        resCriteria[i] = criteria(m.values[i], m.nCols);

    for (int i = 1; i < m.nRows; i++) {
        int t = i;
        while (resCriteria[t] < resCriteria[t - 1] && t > 0) {
            swapf(&resCriteria[t], &resCriteria[t - 1]);
            swapRows(m, t, t - 1);
            t--;
        }
    }
    free(resCriteria);
}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int *resCriteria = (int *) malloc(m.nCols * sizeof(int));
    BAD_ALLOC_CHECK(resCriteria);

    for (int i = 0; i < m.nCols; i++) {
        int *currentColumn = (int *) malloc(sizeof(int) * m.nRows);
        BAD_ALLOC_CHECK(currentColumn);

        for (int j = 0; j < m.nRows; j++) {
            currentColumn[j] = m.values[j][i];
        }
        resCriteria[i] = criteria(currentColumn, m.nRows);
        free(currentColumn);
    }
    for (int i = 1; i < m.nCols; i++) {
        int t = i;
        while (resCriteria[t] < resCriteria[t - 1] && t > 0) {
            swap(&resCriteria[t], &resCriteria[t - 1]);
            swapColumns(m, t, t - 1);
            t--;
        }
    }
    free(resCriteria);
}

bool twoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;
    for (int i = 0; i < m1.nRows; i++)
        if (memcmp(m1.values[i], m2.values[i], sizeof(int) * m1.nCols))
            return false;
    return true;
}

bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
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
        for (int j = i + 1; j < m.nCols; j++)
            if (m.values[i][j] != m.values[j][i])
                return false;
    return true;
}

void transposeSquareMatrix(matrix m) {
    if (!isSquareMatrix(m)) {
        IS_NOT_SQUARE_MATRIX;
    }
    for (int i = 0; i < m.nRows; i++)
        for (int j = i + 1; j < m.nCols; j++)
            swap(&m.values[i][j], &m.values[j][i]);
}

matrix copyMatrix(matrix m) {
    matrix m1 = getMemMatrix(m.nRows, m.nCols);
    for (int i = 0; i < m1.nRows; ++i) {
        memcpy(m1.values[i], m.values[i], sizeof(int));
        memcpy(m1.values, m.values, sizeof(int));
    }
    return m1;
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

//

void swapColsMinAndMaxValue(matrix m) {
    swapRows(m, getMinValuePos(m).rowIndex, getMaxValuePos(m).rowIndex);
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (!isSymmetricMatrix(*m))
        return;
    *m = mulMatrices(*m, *m);;
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    return isEMatrix(mulMatrices(m1, m2));
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix *m) {
    long long *result = (long long *) malloc(m->nRows * sizeof(long long));
    BAD_ALLOC_CHECK(result);
    for (int i = 0; i < m->nRows; i++)
        result[i] = getSum(m->values[i], m->nCols);
    if (!isUnique(result, m->nRows))
        transposeSquareMatrix(*m);
}

void sortRowsByMaxElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

//TODO переделать функцию
int findMaxOfDiagonal(matrix m, size_t indexRow, size_t indexCol) {
    int max = m.values[indexRow][indexCol];
    while (indexRow < m.nRows && indexCol < m.nCols) {
        if (m.values[indexRow][indexCol] > max) {
            max = m.values[indexRow][indexCol];
        }
        indexCol++;
        indexRow++;
    }

    return max;
}

int findSumMaxesOfPseudoDiagonal(matrix m) {
    int sumValue = 0;
    for (size_t iDisplace = 1; iDisplace < m.nCols; iDisplace++)
        sumValue += findMaxOfDiagonal(m, 0, iDisplace);
    for (size_t jDisplace = m.nRows - 1; jDisplace > 0; jDisplace--)
        sumValue += findMaxOfDiagonal(m, jDisplace, 0);

    return sumValue;
}

int getMinInArea(matrix m) {
    position maxValue = getMaxValuePos(m);
    int iColumn = maxValue.rowIndex;
    int leftBorder = maxValue.colIndex;
    int rightBorder = maxValue.colIndex - 1;
    int minValue = m.values[iColumn][maxValue.colIndex];
    while (iColumn >= 0) {
        for (int i = leftBorder; i <= rightBorder; i++)
            if (minValue > m.values[iColumn][i])
                minValue = m.values[iColumn][i];

        if (leftBorder > 0)
            leftBorder--;
        if (rightBorder < m.nCols)
            rightBorder++;
        iColumn--;
    }
    return minValue;
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

int countEqClassesByRowsSum(matrix m) {
    long long *sum = malloc(sizeof(long long) * m.nRows);
    for (int i = 0; i < m.nRows; i++)
        sum[i] = getSum(m.values[i], m.nCols);

    int res = countNUnique(sum, m.nRows);
    free(sum);

    return res;
}

int getNSpecialElement(matrix m) {
    int *sum = malloc(sizeof(int) * m.nRows);
    int *columns = malloc(sizeof(int) * m.nRows);

    for (int i = 0; i < m.nCols; i++)
        for (int j = 0; j < m.nRows; j++) {
            columns[j] = m.values[j][i];
            sum[i] = getSum(columns, m.nRows);
        }
    int count = 0;
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (m.values[i][j] > sum[i] - m.values[i][j])
                count++;
        }
    }

    free(columns);
    free(sum);

    return count;
}

void swapPenultimateRow(matrix m) {
    int minElementInCols = getMinValuePos(m).colIndex;
    for (int i = m.nRows - 1; i >= 0; i++)
        m.values[m.nRows - 2][i] = m.values[i][minElementInCols];
}

int countValues(const int *a, int n, int value) {
    int count = 0;
    for (int i = 0; i < n; i++)
        count += a[i] == value;
    return count;
}

int countZeroRows(matrix m) {
    int count = 0;
    for (int i = 0; i < m.nRows; i++)
        count += countValues(m.values[i], m.nCols, 0) == m.nCols;
    return count;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int *msMaxZeroRowsMatrices = malloc(sizeof(int) * nMatrix);
    BAD_ALLOC_CHECK(msMaxZeroRowsMatrices);
    int max = 0;
    for (int i = 0; i < nMatrix; i++) {
        msMaxZeroRowsMatrices[i] = countZeroRows(ms[i]);
        max = max2(max, countZeroRows(ms[i]));
    }
    for (int i = 0; i < nMatrix; i++)
        if (msMaxZeroRowsMatrices[i] == max)
            outputMatrix(ms[i]);

    free(msMaxZeroRowsMatrices);
}

bool isNonDescendingSorted(int *a, int n) {
    for (int i = 1; i < n; i++)
        if (a[i] < a[i - 1])
            return false;
    return true;
}

bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        if (!isNonDescendingSorted(m.values[i], m.nCols))
            return false;
    return true;

}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int count = 0;
    for (int i = 0; i < nMatrix; i++)
        count += hasAllNonDescendingRows(ms[i]);
    return count;
}

int normMaxInMatrix(matrix m) {
    position minPos = getMinValuePos(m);
    position maxPos = getMaxValuePos(m);
    int normMax = max2(abs(m.values[maxPos.rowIndex][maxPos.colIndex]),
                       abs(m.values[minPos.rowIndex][minPos.colIndex]));
    return normMax;
}

void printMatrixWithMinNorm(matrix *ms, int nMatrix) {
    int *msNorm = malloc(sizeof(int) * nMatrix);
    BAD_ALLOC_CHECK(msNorm);

    for (int i = 0; i < nMatrix; i++)
        msNorm[i] = normMaxInMatrix(ms[i]);

    int min = getMin(msNorm, nMatrix);
    for (int i = 0; i < nMatrix; i++)
        if (msNorm[i] == min)
            outputMatrix(ms[i]);
    free(msNorm);
}