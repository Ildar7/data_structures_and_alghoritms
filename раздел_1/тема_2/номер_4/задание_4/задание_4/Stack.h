#ifndef DATA_PROCESSING_STRUCTURES_AND_ALGORITHMS_STACK_H
#define DATA_PROCESSING_STRUCTURES_AND_ALGORITHMS_STACK_H

#include <iostream>
#include <cstdlib>
#include <clocale>
using namespace std;


struct Stack {
    int value;
    Stack* next;
} *sp, * sp_auxiliary;


void init() {
    sp = NULL;
    sp_auxiliary = NULL;
}

#endif //DATA_PROCESSING_STRUCTURES_AND_ALGORITHMS_STACK_H