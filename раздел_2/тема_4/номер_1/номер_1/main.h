#ifndef DATA_PROCESSING_STRUCTURES_AND_ALGORITHMS_MAIN_H
#define DATA_PROCESSING_STRUCTURES_AND_ALGORITHMS_MAIN_H


//�������������� ���������� ��� ��������� ������ ������
#include <iostream>
#include <clocale>
using namespace std;
//��� ������� - ������ ��� ��������� ������
//��� ������� ����� ������������ ������

//��� �������-������� ��������� ������� ��� �������� ����� ����������� ������

int _hash(char* word)
{
    int sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += word[i];
    }
    sum = sum % 10 + 1;
    return sum;
}

int search(char* key, char** table)
{
    int index = _hash(key);
    if (strcmp(table[index], key) == 0)
    {
        return index;
    }
    else
    {
        return -1;
    }
}


#endif //DATA_PROCESSING_STRUCTURES_AND_ALGORITHMS_MAIN_H
