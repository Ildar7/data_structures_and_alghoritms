#include "three.h"


int main()
{
    setlocale(LC_ALL, "Russian");
    list = new Main_List;
    list->NextM = NULL;
    list->sub = NULL;
    int select = 0;
    while (select != 7)
    {
        cout << "Меню \n1) Добавить элемент в основной список\n2) Добавить элемент во вспомогательный список\n3) Удалит элемент из основного списка\n4) Удалить элемент из вспомогательного списка\n5) Найти элемент \n6) Показать\n7) Выйти\nЧто делаем: ";
        cin >> select;
        if (select == 1) {
            int _value;
            cout << "1) Добавить ДО\n2) Добавить ПОСЛЕ\n";
            cin >> _value;
            if (_value == 1) {
                Before(list);
            }
            else if (_value == 2) {
                After(list);
            }
        }
        else if (select == 2) {
            pushSub(list);
        }
        else if (select == 3) {
            pop(list);
        }
        else if (select == 4) {
            popS(list);
        }
        else if (select == 5) {
            Search(list);
        }
        else if (select == 6) {
            Show(list);
        }
        else if (select == 7) {
            break;
        }
    }
}