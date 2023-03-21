#ifndef DATA_PROCESSING_STRUCTURES_AND_ALGORITHMS_SECOND_H
#define DATA_PROCESSING_STRUCTURES_AND_ALGORITHMS_SECOND_H

#include "Stack.h"
#include "Stack_methods.h"

void MoveToSecondStack()
{
    if (!isEmpty(sp)) {
        Stack* current = sp;
        sp = sp->next;
        current->next = sp_auxiliary;
        sp_auxiliary = current;
        cout << "����������� � ��������������� ������ �����������" << endl;
    }
    else {
        cout << "���� ����, �������� �������� ����������" << endl;
    }
}

void add_from_second()
{
    if (!isEmpty(sp_auxiliary)) {
        Stack* current = sp_auxiliary;
        sp_auxiliary = sp_auxiliary->next;
        current->next = sp;
        sp = current;
    }
    else {
        cout << "��������������� ���� ����, ���������� �������� �� ��������" << endl;
    }

}

#endif //DATA_PROCESSING_STRUCTURES_AND_ALGORITHMS_SECOND_H
