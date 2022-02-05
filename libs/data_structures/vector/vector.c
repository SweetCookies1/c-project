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

}

void deleteVector(vector *v) {
    free(v->data);
}
