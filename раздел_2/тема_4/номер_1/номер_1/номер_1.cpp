#include "main.h"


int main()
{
    setlocale(LC_ALL, "RU");
    char* k = (char*)malloc(256 * sizeof(char));
    char** table = (char**)malloc(10 * sizeof(char*));
    for (int i = 0; i < 10; i++)
    {
        table[i] = NULL;
    }
    int select = 0;
    while (select != 4)
    {
        cout << "\nМеню программы:\n1)Добавить\n2)Показать\n3)Найти\n4)Выйти\n";
        cout << "Выберите вариант: ";
        cin >> select;
        if (select == 1)
        {
            char* key = (char*)malloc(256 * sizeof(char));
            cout << "Введите ключ-слово:\n";
            cin >> key;
            int index = _hash(key);
            if (table[index] == NULL)
            {
                table[index] = (char*)malloc(sizeof(key));
                table[index] = key;
                cout << "Элемент добавлен\n";
            }
            else
            {
                if (table[index] != NULL)
                {
                    cout << "Элемент уже существует\n";
                }
            }
        }
        else if (select == 2)
        {
            if (table != NULL)
            {
                cout << "Хэш-таблица:\n";
                for (int i = 0; i < 10; i++)
                {
                    if (table[i] != NULL)
                    {
                        cout << "Индекс:" << i << " " << "Ключ:" << table[i] << "\n";
                    }
                }
            }
            else
            {
                cout << "Таблица пуста\n";
            }
        }
        else if (select == 3)
        {
            if (table != NULL)
            {
                cout << "Введите ключ, который вы хотите найти:\n";
                cin >> k;
                int index = _hash(k);
                if (strcmp(table[index], k) == 0)
                {
                    cout << "Индекс:" << index << endl;
                }
                else
                {
                    cout << "Не найдено\n";
                }
            }
            else
            {
                cout << "Таблица пуста\n";
            }
        }
        else if (select == 4)
        {
            break;
        }
    }
}