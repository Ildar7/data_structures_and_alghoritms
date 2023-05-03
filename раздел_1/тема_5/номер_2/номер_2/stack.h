#ifndef DATA_PROCESSING_STRUCTURES_AND_ALGORITHMS_STACK_H
#define DATA_PROCESSING_STRUCTURES_AND_ALGORITHMS_STACK_H

#include "balanced_tree.h"

struct Stack {
    int level; //"�������" �������
    Tp* Point; //��������� �� ���������� ������� ������
    Stack* next; //��������� �� ��������� ������� �����
} *sp; // sp - ��������� ������� �������� �����


//�������������, �������� ������� �����
inline void initStack(Tp* pRoot) {
    sp = new Stack;
    sp->Point = pRoot;
    sp->level = -1;
    sp->next = NULL;
}

// �������� ������� �����
bool isEmpty() {
    if (sp->level < 0) return 1;
    else return 0;
}

#endif //DATA_PROCESSING_STRUCTURES_AND_ALGORITHMS_STACK_H
