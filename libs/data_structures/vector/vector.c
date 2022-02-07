#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

//
// Created by user on 05.02.2022.
//

#include "vector.h"

vector createVector(size_t size) {
    vector v = {(int *) (malloc(sizeof(int) * size)), 0, size};
    if (v.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return v;
}

void reserve(vector *v, size_t newCapacity) {
    if(newCapacity == 0)
        v->data = NULL;
    else if (newCapacity <= v->size)
        v->size = newCapacity;
    else if (v->capacity < newCapacity) {
        v->capacity = newCapacity;
        v->data = (int *) realloc(v->data, sizeof(int) * v->capacity);
    }
    else {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    v->data[v->size] = x;
    v->size++;
}

void popBack(vector *v) {
    v->size--;

}

int *atVector(vector *v, size_t index) {
    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[index] is not exist");
        exit(1);
    } else
        return &v->data[index];
}

int *back(vector *v) {
    return atVector(v, v->size - 1);
}

int *front(vector *v) {
    return atVector(v, 0);
}

