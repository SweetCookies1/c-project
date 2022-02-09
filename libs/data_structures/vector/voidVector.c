#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

//
// Created by user on 09.02.2022.
//

#include "voidVector.h"

void empty_vector_happening() {
    fprintf(stderr, "vector is empty");
    exit(1);
}

void bad_alloc_happening() {
    fprintf(stderr, "bad alloc");
    exit(1);
}

vectorVoid createVectorVoid(size_t n, size_t baseTypeSize) {
    void *data = (void *) malloc(baseTypeSize * n);
    if (data == NULL)
        bad_alloc_happening();
    return (vectorVoid) {n == 0 ? NULL : data, 0, n, baseTypeSize};
}

void reserveVoid(vectorVoid *v, size_t newCapacity) {
    v->size = (v->size > newCapacity) ? newCapacity : v->size;
    v->capacity = newCapacity;
    v->data = (int *) realloc(v->data, v->baseTypeSize * newCapacity);
    if (v->data == NULL && newCapacity)
        bad_alloc_happening();
}

void clearVoid(vectorVoid *v) {
    v->size = 0;
}

void shrinkToFitVoid(vectorVoid *v) {
    reserveVoid(v, v->size);
}

void deleteVectorVoid(vectorVoid *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

bool isEmptyVoid(vectorVoid *v) {
    return v->size == 0;
}

bool isFullVoid(vectorVoid *v) {
    return v->size == v->capacity;
}

int getVectorValue(vectorVoid *v, size_t i) {
    return v->data[i];
}

void pushBack(vectorVoid *v, int x) {
    if (isFullVoid(v)) {
        if (v->capacity == 0)
            reserveVoid(v, 1);
        else
            reserveVoid(v, v->capacity * 2);
    }
    v->data[v->size] = x;
    v->size++;
}

void popBackVoid(vectorVoid *v) {
    if (isEmptyVoid(v))
        empty_vector_happening();
    v->size--;
}

int *atVectorVoid(vectorVoid *v, size_t index) {
    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[%zu] is missing", index);
        exit(1);
    } else
        return &v->data[index];
}

int *backVoid(vectorVoid *v) {
    if (isEmptyVoid(v))
        empty_vector_happening();
    return atVectorVoid(v, v->size - 1);
}

int *frontVoid(vectorVoid *v) {
    if (isEmptyVoid(v))
        empty_vector_happening();
    return atVectorVoid(v, 0);
}