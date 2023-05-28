#include "main.h"


int main() {
    setlocale(LC_ALL, "RU");
    int size;
    cout << "\nВведите длину массива: ";
    cin >> size;
    create(size);
    cout << "\nМассив: ";
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    int select = 0;
    while (select != 5) {
        cout << "\nМеню программы:\n1)Сортировка по методу Шелла\n2)Быстрая сортировка\n3)Пирамидальная сортировка\n4)Перегенерировать массив\n5)Выход\n";
        cout << "Введите ваш выбор: ";
        cin >> select;
        if (select == 1)
        {
            Shell(a, size);
        }
        else if (select == 2) {
            unsigned long changes = 0, compares = 0;
            int* m = (int*)malloc(size * sizeof(int));
            memcpy(m, a, size * sizeof(int));
            quicksort(m, 0, size - 1, changes, compares);
            for (int i = 0; i < size; i++)
            {
                cout << m[i] << " ";
            }
            cout << "\nЧисло выполненных сравнений: " << compares << "\nЧисло выполненных перестановок: " << changes;
        }
        else if (select == 3)
        {
            pyramid_sort(size);
        }
        else if (select == 4) {
            create(size);
        }
    }
}