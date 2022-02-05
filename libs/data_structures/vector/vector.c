#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

//
// Created by user on 05.02.2022.
//

#include "vector.h"

vector createVector(size_t n) {
    vector v = {(int *) (malloc(sizeof(int) * n)), 0, n};
    if(v.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return v;
}

void reverse(vector *v, size_t newCapacity) {
    if(newCapacity == 0)
        v->data = NULL;
    else if (newCapacity < v->size)
        v->size = newCapacity;
    else

}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->data = (int *) realloc(v->data,sizeof(int) * v->size);
}

void deleteVector(vector *v) {
    free(v->data);
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->data == sizeof(int) * v->capacity ;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {


}

void popBack(vector *v) {

}