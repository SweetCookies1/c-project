#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "libs/data_structures/vector/vector.h"


void test() {
    vector v = createVector(5);
    pushBack(&v, 6);
    assert(v.size == 6);
}

int main() {

    test();

    return 0;
}

