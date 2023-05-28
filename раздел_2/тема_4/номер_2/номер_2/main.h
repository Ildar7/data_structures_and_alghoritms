#ifndef DATA_PROCESSING_STRUCTURES_AND_ALGORITHMS_MAIN_H
#define DATA_PROCESSING_STRUCTURES_AND_ALGORITHMS_MAIN_H


//внутреннее хеширование
#include <iostream>
#include <clocale>

using namespace std;
//внутреннее хеширование
//если два ключа претендуют на одно место тоЅЅ то он помещаетс€ в след €чейку
//хеш - таблица - массив, заполненный элементами исходного набора в пор€дке, определ€емом хеш - функцией.

int _hash(char* word, int m)
{
    int sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += word[i];
    }
    return sum % m + 1;
}


#endif //DATA_PROCESSING_STRUCTURES_AND_ALGORITHMS_MAIN_H
