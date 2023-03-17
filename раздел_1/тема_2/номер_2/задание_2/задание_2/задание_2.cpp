#include <iostream>
#include <clocale>

class Stack {
    private:
        int* arr; // указатель на массив элементов стека
        int top;
        int size; // текущий размер стека

    public:
        Stack() {
            top = -1;
            size = 0;
            arr = nullptr; // инициализация пустого стека
        }

        bool isEmpty() {
            return (top == -1);
        }

        void push(int data) {
            top++;
            size++;
            int* new_arr = new int[size];
            for (int i = 0; i < size - 1; i++) {
                new_arr[i] = arr[i];
            }
            new_arr[size - 1] = data;
            delete[] arr;
            arr = new_arr;
        }

        int pop() {
            if (isEmpty()) {
                std::cout << "Стек пуст, нечего удалять!" << std::endl;
                return -1;
            }
            int data = arr[top];
            top--;
            size--;
            int* new_arr;
            if (size > 0) {
                new_arr = new int[size];
                for (int i = 0; i < size; i++) {
                    new_arr[i] = arr[i];
                }
            }
            else {
                new_arr = nullptr;
            }
            delete[] arr;
            arr = new_arr;
            return data;
        }

        void display() {
            if (isEmpty()) {
                std::cout << "Стек пуст" << std::endl;
                return;
            }
            std::cout << "Элементы стека: ";
            for (int i = top; i >= 0; i--) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }

        ~Stack() {
            delete[] arr;
        }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Stack stack;
    int choice, data;
    while (true) {
        std::cout << "1. Добавить элемент в стек" << std::endl;
        std::cout << "2. Удалить элемент из стека" << std::endl;
        std::cout << "3. Вывести стек" << std::endl;
        std::cout << "4. Закончить работу программы" << std::endl;
        std::cout << "Что выбираете: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << "Введите добавляемый элемент: ";
            std::cin >> data;
            stack.push(data);
            break;
        case 2:
            data = stack.pop();
            if (data != -1) {
                std::cout << "Удаленный элемент: " << data << std::endl;
            }
            break;
        case 3:
            stack.display();
            break;
        case 4:
            exit(0);
        default:
            std::cout << "Некорректный выбор!" << std::endl;
        }
    }
    return 0;
}