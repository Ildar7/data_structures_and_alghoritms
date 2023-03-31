#ifndef DATA_PROCESSING_STRUCTURES_AND_ALGORITHMS_FOUR_H
#define DATA_PROCESSING_STRUCTURES_AND_ALGORITHMS_FOUR_H


//ЛИНЕЙНЫЙ СПИСОК НА БАЗЕ МАССИВА С УКАЗАТЕЛЯМИ - ИНДЕКСАМИ

#include <iostream>
#include <string>
#include <clocale>
using namespace std;
const int array_size = 11; // размер создаваемого массива
int counter; //счетчик количества элементов

int failure();
inline void initList();
bool isEmpty();
bool isFull();
void Show();
void push();
void pop();
void find();
int find(string _value, int act);
inline void Clear();
void menu();

int failure() {
    int a;
    while (!(cin >> a) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "\nОшибка. Попробуйте снова. \n" << endl;
    }
    return a;
}
//структура линейный список с указателями индексами
struct LinkedList {
    string value; //значение элемента
    int next; //номер ячейки масива, в которой находится следующий элемент
} list[array_size];

void initList() {
    list[0].value = "HEAD"; //заголовок
    list[0].next = 0;
    for (int i = 1; i < array_size; i++) list[i].next = -1; //все ячейки после заголовка отмечаются как свободные
    counter = 0;
}

bool isEmpty() {//проверка на пустоту
    if (list[0].next == 0) return 1;
    else return 0;
}

bool isFull() {//проверка на заполненность
    if (counter == array_size) return 1;
    else return 0;
}

void Show() {//проход по списку и вывод состояния
    if (!isEmpty())//проверка на пустоту
    {
        cout << "\n" << counter << " из " << array_size - 1 << " ячеек заполнено \n";
        int i = 1, current = list[0].next;
        while (current != 0) {
            cout << i << ") " << list[current].value << " (ячейка памяти: " << current << ")\n";
            current = list[current].next;
            i++;
        }
    }
    else  cout << "\nСписок пуст\n";
}

void push() {
    //добавление элемента в список
    if (!isFull()) {
        string _value;
        if (!isEmpty()) {
            //если в списке есть элементы помимо заголовчного, спросить как добавить элемент
            int choice = -1, i = -1, j = 0, s = -1;//i- индекс найденного элемента ,j-индекс свободной ячейки(добавляемой),s-предшественник искомого i
            while ((choice != 0) && (choice != 1)) {
                cout << "\nКуда добавить элемент?\n0 - до\n1 - после";
                cout << "\nВыберите действие: ";
                choice = failure();//вводим номер команды с проверкой на ошибку
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (choice == 0) {//добавление перед заданным элементом
                    i = -1, s = -1;
                    while ((i == -1) || (s == -1)) {
                        cout << "\nВведите значение элемента, ПЕРЕД которым следует ввести новый элемент: "; cin.clear(); getline(cin, _value);
                        i = find(_value, 1);
                        s = find(_value, 0);
                        if ((i == -1) && (s == -1)) cout << "\nЭлемент" << _value << "не найден/ Попробуйте снова";
                    }
                    j = list[0].next;
                    for (j = 1; j < array_size; j++) if (list[j].next == -1)  break;//поиск свободной ячейки
                    list[j].next = i;
                    list[s].next = j;
                }
                else if (choice == 1) {//добавление после элмента
                    i = -1;
                    while (i == -1) {
                        cout << "\nВведите значение элемента, ПОСЛЕ которого нужно добавить новый элемент: "; cin.clear(); getline(cin, _value);
                        i = find(_value, 1);
                        if (i == -1) cout << "\nЭлемент " << _value << " не найден. Попробуйте снова\n";
                    }
                    for (j = 1; j < array_size; j++) if (list[j].next == -1)break;
                    list[j].next = list[i].next;
                    list[i].next = j;
                }
                else {
                    choice = -1;
                    cout << "\nОшибка. Попробуйте снова.";
                }
            }
            cout << "\nВведите элемент, который вы хотите добавить: "; cin.clear(); getline(cin, _value);
            list[j].value = _value;
            cout << "\nЭлемент добавлен \n";
        }
        else {
            //в случае если список пуст, добавлем элемент в начало
            cout << "\nВведите ваш элемент: ";
            cin.clear(); cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); getline(cin, _value);
            list[1].value = _value;
            list[1].next = 0;
            list[0].next = 1;
        }
        counter++;
    }
    else {
        cout << "\nСписок полон. Вы не можете добавить элемент.";
    }
}

void pop() {
    if (!isEmpty()) {
        Show();
        string _value;
        int i = -1, s = -1;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while ((i == -1) || (s == -1)) {
            cout << "\nВведите значение элемента, который вы хотите удалить: "; cin.clear(); getline(cin, _value);
            i = find(_value, 1);
            s = find(_value, 0);
            if ((i == -1) || (s == -1)) cout << "\nЭлемент " << _value << " не найден. Попробуйте снова. Сейчас вы имеете  " << counter << " элемент(-ов) в списке";
        }
        list[s].next = list[i].next;
        list[i].next = -1;
        counter--;
        cout << "\nЭлемент " << list[i].value << " удален из списка\n";
    }
    else {
        cout << "\nУдалять нечего. Список пуст.\n";
    }
}
void find() {
    if (!isEmpty()) {
        Show();
        string _value;
        cout << "\nВведите значение, которое вы хотите найти: ";
        cin.clear(); cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin, _value);
        int i = 1, current = list[0].next;
        while ((current != 0) && (list[current].value != _value)) {
            current = list[current].next;
            i++;
        }
        if (current != 0) {
            cout << "Элемент " << _value << " найден. Под номером " << i << " (в ячейке памяти #" << (current++) << ")\n";
        }
        else {
            cout << "Элемент " << _value << " не найден\n";
        }
    }
    else {
        cout << "\nНечего искать. Список пуст.\n";
    }
}

int find(string _value, int mode)
{
    int current = list[0].next;
    if (mode == 1) {
        while ((current != 0) && (list[current].value != _value)) {
            current = list[current].next;
        }
    }
    else if (mode == 0) {
        int pred = 0;
        while (current != 0) {
            if (list[current].value == _value) break;
            current = list[current].next;
            pred = list[pred].next;
        }
        return pred;
    }
    if (current != 0) {
        return current;
    }
    else {
        return -1;
    }
}

void Clear() {
    initList();
    cout << "\nСписок очищен\n";
}

#endif //DATA_PROCESSING_STRUCTURES_AND_ALGORITHMS_FOUR_H
