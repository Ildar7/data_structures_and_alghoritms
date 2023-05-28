#include "main.h"


int main()
{
    setlocale(LC_ALL, "RU");
    int size;
    cout << "\nВведите кол-во элементов: ";
    cin >> size;
    int* a = (int*)malloc(size * sizeof(int));
    int select = 0;
    while (select != 5)
    {
        cout << "\nМеню программы:\n1)Карманная сортировка с доп. массивом\n2)Карманная сортировка\n3)Обобщенная карманная сортировка\n4)Поразрядная сортировка\n5)Выход\n";
        cout << "Введите ваш выбор: ";
        cin >> select;
        if (select == 1)
        {
            int i = 0;
            int sup;
            while (i < size)
            {
                sup = rand() % size;
                for (int j = i; j >= 0; j--)
                {
                    if (a[j] == sup)
                    {
                        break;
                    }
                    else if (j == 0)
                    {
                        a[i] = sup;
                        i++;
                    }
                }
            }
            printf("\nМассив: ");
            show(a, size);
            PocketSortWithArray(a, size);
        }
        else if (select == 2) {
            int i = 0;
            int sup;
            while (i < size)
            {
                sup = rand() % size;
                for (int j = i; j >= 0; j--)
                {
                    if (a[j] == sup)
                    {
                        break;
                    }
                    else if (j == 0)
                    {
                        a[i] = sup;
                        i++;
                    }
                }
            }
            printf("\nМассив: ");
            show(a, size);
            PocketsortWithoutArray(a, size);
        }
        else if (select == 3) {
            printf("\nМассив: ");
            for (int i = 0; i < size; i++)
            {
                a[i] = rand() % size;
                cout << a[i] << " ";
            }
            PocketSort(a, size);
        }
        else if (select == 4) {
            printf("\nМассив: ");
            for (int i = 0; i < size; i++)
            {
                a[i] = rand() % 900 + 100;
                cout << a[i] << " ";
            }
            RadixSort(a, size);
        }
        else if (select == 5)
        {
            break;
        }
    }
}

