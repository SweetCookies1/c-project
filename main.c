#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/matrix/matrix.h"

vector createFilledVector(size_t size, size_t capacity) { // Создает и заполняет структру (только для тестов)
    int *data = (int *) malloc(sizeof(int) * capacity);
    for (int i = 0; i < 5; ++i)
        data[i] = i;
    return (vector) {data, size, capacity};
}

void test_createVector_emptyVector() {
    vector v = createVector(0);
    assert(v.size == 0);
    assert(v.capacity == 0);
    assert(v.data == NULL);

    deleteVector(&v);
}

void test_createVector_notEmptyVector() {
    vector v = createVector(10);

    assert(v.size == 0);
    assert(v.capacity == 10);
    assert(v.data != NULL);

    deleteVector(&v);
}

void test_reserve_returnToEmptyVector() {
    vector v = createFilledVector(5, 10);
    reserve(&v, 0);

    assert(v.size == 0);
    assert(v.capacity == 0);
    assert(v.data == NULL);

    deleteVector(&v);
}

void test_reserve_decreaseVector() {
    vector v = createFilledVector(5, 10);
    reserve(&v, 1);

    assert(v.size == 1);
    assert(v.capacity == 1);
    assert(v.data != NULL);

    deleteVector(&v);
}

void test_reserve_increaseVector() {
    vector v = createFilledVector(5, 5);
    reserve(&v, 10);

    assert(v.size == 5);
    assert(v.capacity == 10);
    assert(v.data != NULL);

    deleteVector(&v);
}

void test_clear_defaultVector() {
    vector v = createFilledVector(5, 10);
    clear(&v);

    assert(v.size == 0);
    assert(v.capacity == 10);
    assert(v.data != NULL);

    deleteVector(&v);
}

void test_isEmpty_emptyVector() {
    vector v = createVector(0);

    assert(isEmpty(&v));

    deleteVector(&v);
}

void test_isEmpty_reservedMemoryVector() {
    vector v = createVector(10);

    assert(isEmpty(&v));

    deleteVector(&v);
}

void test_isEmpty_notEmptyVector() {
    vector v = createFilledVector(5, 10);

    assert(!isEmpty(&v));

    deleteVector(&v);
}

void test_isFull_emptyVector() {
    vector v = createVector(0);

    assert(isFull(&v));

    deleteVector(&v);
}

void test_isFull_fullVector() {
    vector v = createFilledVector(10, 10);

    assert(isFull(&v));

    deleteVector(&v);
}


void test_isFull_notFullVector() {
    vector v = createFilledVector(5, 10);
    assert(!isFull(&v));

    deleteVector(&v);
}

void test_getVectorValue_defaultVector() {
    vector v = (vector) {(int[]) {5, 10, 0, 15, 20}, 5, 5};

    assert(getVectorValue(&v, 3) == 15);
}

void test_pushBack_notReservedMemoryVector() {
    vector v = createVector(0);
    pushBack(&v, 18);

    assert(v.size == 1);
    assert(v.capacity == 1);

    deleteVector(&v);
}

void test_pushBack_ReservedMemoryVector() {
    vector v = createVector(10);
    pushBack(&v, 18);

    assert(v.size == 1);
    assert(v.capacity == 10);

    deleteVector(&v);
}

void test_pushBack_fullVector() {
    vector v = createFilledVector(5, 5);
    pushBack(&v, 18);

    assert(v.size == 6);
    assert(v.capacity == 10);

    deleteVector(&v);
}

void test_pushBack_defaultVector() {
    vector v = createFilledVector(5, 10);
    pushBack(&v, 18);

    assert(v.size == 6);
    assert(v.capacity == 10);

    deleteVector(&v);
}

void test_popBack_notEmptyVector() {
    vector v = createFilledVector(5, 10);
    popBack(&v);

    assert(v.size == 4);
    assert(v.capacity == 10);

    deleteVector(&v);
}

void test_shrinkToFit_fullVector() {
    vector v = (vector) createFilledVector(5, 5);
    shrinkToFit(&v);

    assert(v.size == 5);
    assert(v.capacity == 5);
}

void test_shrinkToFit_defaultVector() {
    vector v = createFilledVector(5, 10);;
    shrinkToFit(&v);

    assert(v.size == 5);
    assert(v.capacity == 5);

    deleteVector(&v);
}

void test_atVector_notEmptyVector() {
    vector v = (vector) {(int[]) {6, 12, 24, 48, 96}, 5, 5};

    assert(*atVector(&v, 1) == 12);
}

void test_atVector_requestToLastElement() {
    vector v = (vector) {(int[]) {12, 28, 99}, 3, 3};

    assert(*atVector(&v, 2) == 99);
}

void test_back_oneElementInVector() {
    vector v = (vector) {(int[]) {79}, 1, 1};

    assert(*back(&v) == 79);
}

void test_back_defaultVector() {
    vector v = (vector) {(int[]) {346, 1, 55, 90}, 4, 4};

    assert(*back(&v) == 90);
}

void test_front_oneElementInVector() {
    vector v = (vector) {(int[]) {79}, 1, 1};

    assert(*front(&v) == 79);
}

void test_front_defaultVector() {
    vector v = (vector) {(int[]) {346, 1, 55, 90}, 4, 4};

    assert(*front(&v) == 346);
}

void test_vector() {
    test_createVector_emptyVector();
    test_createVector_notEmptyVector();

    test_reserve_returnToEmptyVector();
    test_reserve_decreaseVector();
    test_reserve_increaseVector();

    test_clear_defaultVector();

    test_shrinkToFit_fullVector();
    test_shrinkToFit_defaultVector();

    test_isEmpty_emptyVector();
    test_isEmpty_notEmptyVector();
    test_isEmpty_reservedMemoryVector();

    test_isFull_emptyVector();
    test_isFull_fullVector();
    test_isFull_notFullVector();

    test_getVectorValue_defaultVector();

    test_pushBack_notReservedMemoryVector();
    test_pushBack_ReservedMemoryVector();
    test_pushBack_fullVector();
    test_pushBack_defaultVector();

    test_popBack_notEmptyVector();

    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();

    test_back_oneElementInVector();
    test_back_defaultVector();

    test_front_oneElementInVector();
    test_front_defaultVector();
}

int main() {
    test_vector();
    return 0;
}
