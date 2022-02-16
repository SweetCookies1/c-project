#include <assert.h>
#include <stdbool.h>
#include "libs/data_structures/matrix/matrix.h"

void test_swapRows1() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    3, 5, 7,
                    1, 9, 0,
                    45, 6, 13
            },
            3, 3);
    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    1, 9, 0,
                    3, 5, 7,
                    45, 6, 13
            },
            3, 3);
    swapRows(testMatrix, 0, 1);

    assert(twoMatricesEqual(testMatrix, expectedMatrix));
}

void test_swapRows2() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    3, 5, 7,
                    1, 9, 0,
                    45, 6, 13
            },
            3, 3);
    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    3, 5, 7,
                    45, 6, 13,
                    1, 9, 0
            },
            3, 3);

    swapRows(testMatrix, 1, 2);

    assert(twoMatricesEqual(testMatrix, expectedMatrix));
}

void test_swapRows3() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    3, 5, 7,
                    1, 9, 0,
                    45, 6, 13
            },
            3, 3);
    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    45, 6, 13,
                    1, 9, 0,
                    3, 5, 7,
            },
            3, 3);
    swapRows(testMatrix, 0, 2);

    assert(twoMatricesEqual(testMatrix, expectedMatrix));
}

void test_swapRows() {
    test_swapRows1();
    test_swapRows2();
    test_swapRows3();
}

void test_swapColumns1() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    3, 5, 7,
                    1, 9, 0,
                    45, 6, 13
            },
            3, 3);
    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    7, 5, 3,
                    0, 9, 1,
                    13, 6, 45
            },
            3, 3);
    swapColumns(testMatrix, 0, 2);

    assert(twoMatricesEqual(testMatrix, expectedMatrix));
}

void test_swapColumns2() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    3, 5, 7,
                    1, 9, 0,
                    45, 6, 13
            },
            3, 3);
    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    3, 7, 5,
                    1, 0, 9,
                    45, 13, 6
            },
            3, 3);
    swapColumns(testMatrix, 1, 2);

    assert(twoMatricesEqual(testMatrix, expectedMatrix));
}

void test_swapColumns3() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    3, 5, 7,
                    1, 9, 0,
                    45, 6, 13
            },
            3, 3);
    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    5, 3, 7,
                    9, 1, 0,
                    6, 45, 13
            },
            3, 3);
    swapColumns(testMatrix, 0, 1);

    assert(twoMatricesEqual(testMatrix, expectedMatrix));
}

void test_swapColumns() {
    test_swapColumns1();
    test_swapColumns2();
    test_swapColumns3();
}


void test_isSquareMatrix1() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    9, 0, 7,
                    5, 4, 0,
                    15, 0, 10,
            },
            3, 3);
    assert(isSquareMatrix(testMatrix));
}

void test_isSquareMatrix2() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    2, 4,
                    1, 5,
            },
            2, 2);
    assert(isSquareMatrix(testMatrix));
}

void test_isSquareMatrix3() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    1
            },
            1, 1);
    assert(isSquareMatrix(testMatrix));
}

void test_isSquareMatrix() {
    test_isSquareMatrix1();
    test_isSquareMatrix2();
    test_isSquareMatrix3();
}

void test_twoMatricesEqual1() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    5, 5, 8,
                    1, 9, 0,
                    11, 8, 10
            },
            3, 3);
    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    5, 5, 8,
                    1, 9, 0,
                    11, 8, 10
            },
            3, 3);

    assert(twoMatricesEqual(testMatrix, expectedMatrix));
}

void test_twoMatricesEqual2() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    1, 5
            },
            1, 2);
    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    1, 5
            },
            1, 2);

    assert(twoMatricesEqual(testMatrix, expectedMatrix));
}

void test_twoMatricesEqual3() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    1, 5,
                    6, 9
            },
            2, 2);
    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    1, 5,
                    6, 8
            },
            2, 2);

    assert(!twoMatricesEqual(testMatrix, expectedMatrix));
}

void test_twoMatricesEqual() {
    test_twoMatricesEqual1();
    test_twoMatricesEqual2();
    test_twoMatricesEqual3();
}

void test_isEMatrix1() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1
            },
            3, 3);
    assert(isEMatrix(testMatrix));
}

void test_isEMatrix2() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    1, 0,
                    0, 1
            },
            2, 2);
    assert(isEMatrix(testMatrix));
}

void test_isEMatrix() {
    test_isEMatrix1();
    test_isEMatrix2();
}

void test_isSymmetricMatrix1() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    2, 1, 4,
                    1, 3, 8,
                    4, 8, 2
            },
            3, 3);

    assert(isSymmetricMatrix(testMatrix));
}


void test_isSymmetricMatrix2() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    5
            },
            1, 1);

    assert(isSymmetricMatrix(testMatrix));
}

void test_isSymmetricMatrix3() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    1, 1,
                    5, 7
            },
            2, 2);

    assert(!isSymmetricMatrix(testMatrix));
}

void test_isSymmetricMatrix() {
    test_isSymmetricMatrix1();
    test_isSymmetricMatrix2();
    test_isSymmetricMatrix3();
}

void test_transposeSquareMatrix1() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    1, 9, 14,
                    7, 3, 7,
                    5, 7, 0
            },
            3, 3);
    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    1, 7, 5,
                    9, 3, 7,
                    14, 7, 0
            },
            3, 3);
    transposeSquareMatrix(testMatrix);

    assert(twoMatricesEqual(testMatrix, expectedMatrix));
}

void test_transposeSquareMatrix2() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    3, 0,
                    8, 1
            },
            2, 2);
    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    3, 8,
                    0, 1
            },
            2, 2);
    transposeSquareMatrix(testMatrix);

    assert(twoMatricesEqual(testMatrix, expectedMatrix));
}

void test_transposeSquareMatrix3() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    3
            },
            1, 1);
    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    3
            },
            1, 1);
    transposeSquareMatrix(testMatrix);

    assert(twoMatricesEqual(testMatrix, expectedMatrix));
}

void test_transposeSquareMatrix() {
    test_transposeSquareMatrix1();
    test_transposeSquareMatrix2();
    test_transposeSquareMatrix3();
}

void test_getMinValuePos1() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    5, 0, 10,
                    6, 0, 6,
                    4, 5, -1
            },
            3, 3);
    position pos = getMinValuePos(testMatrix);
    position minValuePos = {2, 2};

    assert(pos.rowIndex == minValuePos.rowIndex && pos.colIndex == minValuePos.colIndex);
}

void test_getMinValuePos2() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    3, 6, 0,
                    -6, 8, 6,
                    0, 5, 4
            },
            3, 3);
    position pos = getMinValuePos(testMatrix);
    position minValuePos = {1, 0};

    assert(pos.rowIndex == minValuePos.rowIndex && pos.colIndex == minValuePos.colIndex);

}

void test_getMinValuePos3() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    -3, 6, 10,
                    6, 5, 6,
                    0, 5, 100
            },
            3, 3);
    position pos = getMinValuePos(testMatrix);
    position minValuePos = {0, 0};

    assert(pos.rowIndex == minValuePos.rowIndex && pos.colIndex == minValuePos.colIndex);
}

void test_getMinValuePos() {
    test_getMinValuePos1();
    test_getMinValuePos2();
    test_getMinValuePos3();
}

void test_getMaxValuePos1() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    3, 0,
                    -6, 8
            },
            2, 2);
    position pos = getMaxValuePos(testMatrix);
    position maxValuePos = {1, 1};

    assert(pos.rowIndex == maxValuePos.rowIndex && pos.colIndex == maxValuePos.colIndex);
}

void test_getMaxValuePos2() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    3, 30, 6,
                    -6, 8, 6,
                    0, 5, 1
            },
            3, 3);
    position pos = getMaxValuePos(testMatrix);
    position maxValuePos = {0, 1};

    assert(pos.rowIndex == maxValuePos.rowIndex && pos.colIndex == maxValuePos.colIndex);
}

void test_getMaxValuePos3() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    3
            },
            1, 1);
    position pos = getMaxValuePos(testMatrix);
    position maxValuePos = {0, 0};

    assert(pos.rowIndex == maxValuePos.rowIndex && pos.colIndex == maxValuePos.colIndex);
}

void test_getMaxValuePos() {
    test_getMaxValuePos1();
    test_getMaxValuePos2();
    test_getMaxValuePos3();
}

void test_swapColsMinAndMaxValue() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    3, 6, 10,
                    -6, 5, 6,
                    0, 5, -100
            },
            3, 3);

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    0, 5, -100,
                    -6, 5, 6,
                    3, 6, 10
            },
            3, 3);

    swapColsMinAndMaxValue(testMatrix);
    assert(twoMatricesEqual(testMatrix, expectedMatrix));
}

void test_getSquareMatrixIfSymmetric() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    3, 5, 10,
                    5, 3, 5,
                    10, 5, 3
            },
            3, 3);

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    134, 80, 85,
                    80,	59,	80,
                    85,	80,	134
            },
            3, 3);

    getSquareOfMatrixIfSymmetric(&testMatrix);
    assert(twoMatricesEqual(testMatrix, expectedMatrix));
}

void test_transposeIfMatrixHasNotEqualSumOfRows() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    3, 6, 0,
                    -6, 8, 6,
                    90, 5, -10
            },
            3, 3);

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    3, -6, 90,
                    6, 8, 5,
                    0, 6, -10
            },
            3, 3);

    transposeIfMatrixHasNotEqualSumOfRows(&testMatrix);
    assert(twoMatricesEqual(testMatrix, expectedMatrix));
}

void test_isMutuallyInverseMatrices() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    2,  5, 7,
                    6, 3, 4,
                    5, -2, -3
            },
            3, 3);

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    1, -1, 1,
                    -38, 41, -34,
                    27, -29, 24
            },
            3, 3);

    bool i = isMutuallyInverseMatrices(testMatrix, expectedMatrix);
    bool j = true;
    assert(i == j);
}

void test_sortRowsByMaxElement() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    1, 0, 8,
                    7, 5, 20,
                    2, 17, 10,
            },
            3, 3);

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    1, 0, 8,
                    2, 17, 10,
                    7, 5, 20,
            },
            3, 3);

    sortRowsByMaxElement(testMatrix);
    assert(twoMatricesEqual(testMatrix, expectedMatrix));
}

void test_sortColsByMinElement() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    0, 4, 11,
                    10, -1, 15,
                    6, 9, 1,
            },
            3, 3);

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    4, 0, 11,
                    -1, 10, 15,
                    9, 6, 1,
            },
            3, 3);

    sortColsByMinElement(testMatrix);
    assert(twoMatricesEqual(testMatrix, expectedMatrix));
}


void test_sumOfMaxValuesPseudoDiagonal() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    3, 2, 5,
                    1, 3, 6,
                    3, 2, 1
            },
            3, 3);
    int res = findSumMaxesOfPseudoDiagonal(testMatrix);
    assert(16 == res);
}

void test_getMinInArea() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    4, 6, 0,
                    -100, 8, 6,
                    90, 1, 500
            },
            3, 3);
    int res = getMinInArea(testMatrix);
    assert(0 == res);
}

void test_matrix() {

    test_swapRows();
    test_swapColumns();

    test_isSquareMatrix();
    test_twoMatricesEqual();
    test_isEMatrix();
    test_isSymmetricMatrix();

    test_transposeSquareMatrix();

    test_getMinValuePos();
    test_getMaxValuePos();

    test_swapColsMinAndMaxValue();
    test_getSquareMatrixIfSymmetric();
    test_transposeIfMatrixHasNotEqualSumOfRows();
    test_isMutuallyInverseMatrices();
    test_sortColsByMinElement();
    test_sortRowsByMaxElement();
    test_sumOfMaxValuesPseudoDiagonal();
    test_getMinInArea();
}

int main() {
    test_matrix();
    return 0;
}
