#include "main.h"


int main() {
    setlocale(LC_ALL, "RU");
    createarray();
    show(a);
    int choice;
    while (true)
    {
        cout << "\nВыберите вашу команду: ";
        cout << "\n1. Пузырьковая сортировка";
        cout << "\n2. Сортировка вставками";
        cout << "\n3. Сортировка выбором";
        cout << "\n4. Перегенерировать массив";
        cout << "\n0. Выход";
        cout << "\nВаш выбор: ";
        cin >> choice;
        if (choice == 1) { show(a); buble_sort(); }
        else if (choice == 2) { show(a); inser_sort(); }
        else if (choice == 3) { show(a); choice_sort(); }
        else if (choice == 4)createarray();
        else if (choice == 0) break;
        else cout << "\nОшибка. Попробуйте снова.";
    }
    return 0;
}