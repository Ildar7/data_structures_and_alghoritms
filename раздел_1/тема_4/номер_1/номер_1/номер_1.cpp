#include "one.h"


void Menu()
{
    int choice, value, key, add_value;
    bool isWorking = true;
    while (isWorking)
    {
        std::cout << "Меню\n" << "1. Просмотр списка\n" << "2. Добавить элемент в список\n";
        std::cout << "3. Удалить заданный элемент\n" << "4. Поиск заданного элемента\n" << "5. Выход\n" << "Ваш выбор: ";
        choice = Input();
        if (choice == 5)
        {
            isWorking = false;
        }
        else if (choice == 1)
        {
            if (head->next == head)
                std::cout << "Список пуст!\n";
            else
            {
                while (true)
                {
                    std::cout << "В прямом (1) или обратном (0) направлении? \nВаш выбор: ";
                    key = Input();
                    if (key == 1)
                    {
                        Show(true);
                        break;
                    }
                    else if (key == 0)
                    {
                        Show(false);
                        break;
                    }
                    else std::cout << "Команда отсутствует! Повторите попытку\n";
                }
            }
        }
        else if (choice == 2)
        {
            std::cout << "Введите значение: ";
            value = Input();
            if (head->next == head)
                AddAfter(value, 0);
            else
            {
                std::cout << "Добавить до (1) или после (0)? \nВаш выбор: ";
                key = Input();
                if (key == 1)
                {
                    std::cout << "Введите значение до которого необходимо вставить: ";
                    add_value = Input();
                    if (FindValue(add_value, true))
                        AddBefore(value, add_value);
                    else std::cout << "Значение отсутствует!\n";
                }
                else if (key == 0)
                {
                    std::cout << "Введите значение после которого необходимо вставить: ";
                    add_value = Input();
                    if (FindValue(add_value, true))
                        AddAfter(value, add_value);
                    else
                        std::cout << "Значение отсутствует!\n";
                }
                else std::cout << "Команда отсутствует! Повторите попытку\n";
            }
            std::cout << "Добавлено!\n";
        }
        else if (choice == 3)
        {
            if (head->next == head)
                std::cout << "Cписок пуст! Удаление невозможно\n";
            else
            {
                std::cout << "Введите значение: ";
                value = Input();
                if (FindValue(value, true))
                {
                    std::cout << "Удалено!\n";
                    Delete(value);
                }
                else std::cout << "Значение отсутствует в списке!\n";
            }
        }
        else if (choice == 4)
        {
            if (head->next == head)
                std::cout << "Нечего искать! Список пуст!\n";
            else {
                std::cout << "Введите значение: ";
                value = Input();
                while (true)
                {
                    std::cout << "В прямом (1) или обратном (0) направлении? \nВаш выбор: ";
                    key = Input();
                    if (key == 1)
                    {
                        if (FindValue(value, true))
                            std::cout << "Данное значение находится в списке!\n";
                        else
                            std::cout << "Данного значения нет в списке!\n";
                        break;
                    }
                    else if (key == 0)
                    {
                        if (FindValue(value, false))
                            std::cout << "Данное значение находится в списке!\n";
                        else
                            std::cout << "Данного значения нет в списке!\n";
                        break;
                    }
                    else std::cout << "Команда отсутствует! Повторите попытку\n";
                }
            }
            
        }
        else std::cout << "Команда отсутствует\n";
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Init();
    Menu();
}