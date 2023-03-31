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
    int value; //�������������� ����� �������� ������
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
    //������ �� ������ � ��� �����
    if (!isEmpty()) {
        cout << "\n������������� ������ " << counter << "/" << array_size << "\n";
        for (int i = 0; i < counter; i++) {
            cout << i + 1 << ")" << list[i].value << "\n";
        }
    }
    else { cout << "\n������ ����\n"; }
}

void push() {
    if (!isFull()) {
        bool a = 1;
        int _value;
        if (isEmpty()) {
            cout << "\n������ ����. ������� ����� �������� � ������ ������.\n" << "������� ����������� �������: ";
            cin >> _value;
            list[0].value = _value;
            counter++;
            return;
        }
        cout << "\n������� ����������� �������: ";
        cin >> _value;

        for (int i = 0; i < counter; i++) {
            if (_value < list[i].value) {
                if (i == counter) list[counter].value = _value;
                //���������� � �����
                if (i < counter) {
                    for (int k = counter; k > i; k--) //����������� ����� � �����
                        list[k].value = list[k - 1].value;
                    list[i].value = _value; //������ � ����� ������
                }
                a = 0;
                cout << "\n������� �������� � ������ " << i + 1 << "\n";
                break;
            }
        }
        if (a) {
            list[counter].value = _value; //������ � ����� ���� ��� �������� ������ ���������
            cout << "\n������� �������� � ����� ������\n";
        }
        counter++;
    }
    else { cout << "\n���������� ����������. ������ �����\n"; }
}

void pop() {
    if (!isEmpty()) {
        Show();
        int _value;
        cout << "\n������� �������, ������� �� ������ �������: ";
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
                    cout << "\n������� " << _value << " ������. " << "������ �� ������ " << counter << " ��������� � ������.\n";
                }
            }
            if (k == -1) cout << "\n��������� ������� ����������� � ������\n";
        }
    }
    else cout << "\n������ �������. ������ ����\n";
}

void find() {
    if (!isEmpty()) {
        int auxiliary_count = 0;
        Show();
        int _value;
        cout << "\n������� �������, ������� �� ������� �����: ";
        cin >> _value;
        for (int i = 0; i < counter; i++) {
            if (list[i].value == _value) auxiliary_count = i + 1;
        }
        if (auxiliary_count != 0) cout << "\n������� " << _value << " ������.\n��� ���������� �����: " << auxiliary_count << endl;
        else cout << "\n������� " << _value << " �� ������\n";
    }
    else cout << "\n������ ������. ������ ����\n";
}

void clear() {
    for (int i = 0; i < array_size; i++) list[i].value = NULL;
    counter = 0;
    cout << "\n������ ������\n";
}

int failure() {
    int a;
    while (!(cin >> a) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "\n������. ���������� �����. \n" << endl;
    }
    return a;
}


#endif //DATA_PROCESSING_STRUCTURES_AND_ALGORITHMS_SECOND_H
