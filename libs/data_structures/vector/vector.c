#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

//
// Created by user on 05.02.2022.
//

#include "vector.h"

void empty_vector_happening(){
    fprintf(stderr ,"vector is empty");
    exit(1);
}

void bad_alloc_happening(){
    fprintf(stderr, "bad alloc");
    exit(1);
}

vector createVector(size_t n) {
    vector v = {(int *) (malloc(sizeof(int) * n)), 0, n};
    if (v.data == NULL)
        bad_alloc_happening();
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
    else
        bad_alloc_happening();
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
    if (isFull(v)) {
        if(v->capacity == 0)
            reserve(v, 1);
        else
            reserve(v, v->capacity * 2);
    }
    v->data[v->size] = x;
    v->size++;
}

void popBack(vector *v) {
    if(isEmpty(v))
        empty_vector_happening();
    v->size--;
}

int *atVector(vector *v, size_t index) {
    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[%zu] is missing", index);
        exit(1);
    } else
        return &v->data[index];
}

int *back(vector *v) {
    if(isEmpty(v))
        empty_vector_happening();
    return atVector(v, v->size - 1);
}

int *front(vector *v) {
    if (isEmpty(v))
        empty_vector_happening();
    return atVector(v, 0);
}