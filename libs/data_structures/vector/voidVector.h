//
// Created by user on 09.02.2022.
//

#ifndef LABA5B_VOIDVECTOR_H
#define LABA5B_VOIDVECTOR_H

typedef struct vectorVoid {
    int *data;
    size_t size;
    size_t capacity;
    size_t baseTypeSize;
} vectorVoid;

vectorVoid createVectorVoid(size_t size, size_t baseTypeSize);

void reserveVoid(vectorVoid *v, size_t newCapacity);

void clearVoid(vectorVoid *v);

void shrinkToFitVoid(vectorVoid *v);

void deleteVectorVoid(vectorVoid *v);

bool isEmptyVoid(vectorVoid *v);

bool isFullVoid(vectorVoid *v);

int getVectorValueVoid(vectorVoid *v, size_t i);

void pushBackVoid(vectorVoid *v, int x);

void popBackVoid(vectorVoid *v);

int* atVectorVoid(vectorVoid *v, size_t index);

int* backVoid(vectorVoid *v);

int* frontVoid(vectorVoid *v);

#endif //LABA5B_VOIDVECTOR_H
