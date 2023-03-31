#ifndef DATA_PROCESSING_STRUCTURES_AND_ALGORITHMS_SECOND_H
#define DATA_PROCESSING_STRUCTURES_AND_ALGORITHMS_SECOND_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <clocale>

using namespace std;

const int array_size = 10;
int counter;

struct List {
    int value; //информационна€ часть элемента списка
} list[array_size];

void initList() {
    for (int i = 0; i < array_size; i++) list[i].value = NULL;
    counter = 0;
}

int isEmpty() {
    if (counter == 0) return 1;
    else return 0;
}

int isFull() {
    if (counter == array_size) {
        return 1;
    }
    else {
        return 0;
    }
}

void Show() {
    //проход по списку и его показ
    if (!isEmpty()) {
        cout << "\n«аполненность списка " << counter << "/" << array_size << "\n";
        for (int i = 0; i < counter; i++) {
            cout << i + 1 << ")" << list[i].value << "\n";
        }
    }
    else { cout << "\n—писок пуст\n"; }
}

void push() {
    if (!isFull()) {
        bool a = 1;
        int _value;
        if (isEmpty()) {
            cout << "\n—писок пуст. Ёлемент будет добавлен в начало списка.\n" << "¬ведите добавл€емый элемент: ";
            cin >> _value;
            list[0].value = _value;
            counter++;
            return;
        }
        cout << "\n¬ведите добавл€емый элемент: ";
        cin >> _value;

        for (int i = 0; i < counter; i++) {
            if (_value < list[i].value) {
                if (i == counter) list[counter].value = _value;
                //добавление в конец
                if (i < counter) {
                    for (int k = counter; k > i; k--) //копирование €чеек с конца
                        list[k].value = list[k - 1].value;
                    list[i].value = _value; //запись в новую €чейку
                }
                a = 0;
                cout << "\nЁлемент добавлен в €чейку " << i + 1 << "\n";
                break;
            }
        }
        if (a) {
            list[counter].value = _value; //запись в конец если все элементы меньше заданного
            cout << "\nЁлемент добавлен в конец списка\n";
        }
        counter++;
    }
    else { cout << "\nƒобавление невозможно. —писок полон\n"; }
}

void pop() {
    if (!isEmpty()) {
        Show();
        int _value;
        cout << "\n¬ведите элемент, который вы хотите удалить: ";
        cin >> _value;
        int k = -1;
        while (k == -1) {
            for (int i = 0; i < counter; i++) {
                if (list[i].value == _value) {
                    k++;
                    for (int k = i; k < counter; k++) {
                        list[k].value = list[k + 1].value;
                    }
                    counter--;
                    cout << "\nЁлемент " << _value << " удален. " << "—ейчас вы имеете " << counter << " элементов в списке.\n";
                }
            }
            if (k == -1) cout << "\n¬веденный элемент отсутствует в списке\n";
        }
    }
    else cout << "\nЌечего удал€ть. —писок пуст\n";
}

void find() {
    if (!isEmpty()) {
        int auxiliary_count = 0;
        Show();
        int _value;
        cout << "\n¬ведите элемент, который вы желаете найти: ";
        cin >> _value;
        for (int i = 0; i < counter; i++) {
            if (list[i].value == _value) auxiliary_count = i + 1;
        }
        if (auxiliary_count != 0) cout << "\nЁлемент " << _value << " найден.\n≈го пор€дковый номер: " << auxiliary_count << endl;
        else cout << "\nЁлемент " << _value << " не найден\n";
    }
    else cout << "\nЌечего искать. —писок пуст\n";
}

void clear() {
    for (int i = 0; i < array_size; i++) list[i].value = NULL;
    counter = 0;
    cout << "\n—писок очищен\n";
}

int failure() {
    int a;
    while (!(cin >> a) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "\nќшибка. ѕопробуйте снова. \n" << endl;
    }
    return a;
}


#endif //DATA_PROCESSING_STRUCTURES_AND_ALGORITHMS_SECOND_H
