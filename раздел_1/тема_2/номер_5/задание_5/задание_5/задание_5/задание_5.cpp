#include "RingQueue.h"

int fail() {
    int a;
    while (!(cin >> a) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Ошибка попробуйте снова" << endl;
    }
    return a;
}

void menu(int* queue_array) {
    while (true) {
        int menu_number, auxiliary_value;
        cout << "\nВыберите команду:" << endl;
        cout << "1. Добавить элемент в конец очереди" << endl;
        cout << "2. Удалить элемент из очереди" << endl;
        cout << "3. Показать очередь" << endl;
        cout << "4. Завершить программу" << endl;
        cout << "Что делаем: ";
        menu_number = fail();

        if (menu_number == 1) {
            if (!IsFull()) {
                cout << "Введите значение" << endl;
                int auxiliary_value = fail();
                push(queue_array, auxiliary_value);
            }
            else {
                cout << "Очередь полна" << endl;
            }
        }
        else if (menu_number == 2) {
            int value = pop(queue_array);
            if (value != -1) {
                cout << "Элемент " << value << " удален" << endl;;
            }
        }
        else if (menu_number == 3) {
            cout << "Текущая очередь: " << endl;
            show_queue(queue_array);
        }
        else if (menu_number == 4) {
            exit(0);
        }
        else {
            cout << "Ошибка попробуйте снова" << endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int queue_array[array_size];
    menu(queue_array);
    return 0;
}