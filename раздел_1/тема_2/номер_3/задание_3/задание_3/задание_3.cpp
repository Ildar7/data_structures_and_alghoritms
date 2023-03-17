#include <iostream>
#include <clocale>
#include <cstdlib>
#include <ctime>

class Stack {
    private:
        int* arr;
        int top;
        int size;

    public:
        Stack() {
            top = -1;
            size = 0;
            arr = nullptr;
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

        void pushMultiple(int count) {
            srand(time(nullptr));
            for (int i = 0; i < count; i++) {
                push(rand());
            }
        }

        int pop() {
            if (isEmpty()) {
                std::cout << "Стек пуст, нечего удалять!" << std::endl;
                return -1;
            }
            int data = arr[top];
            top--;
            size--;
            int* new_arr = new int[size];
            for (int i = 0; i < size; i++) {
                new_arr[i] = arr[i];
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
    std::srand(std::time(nullptr));
    Stack stack;
    int choice, data;
    while (true) {
        std::cout << "1. Добавить элемент в стек" << std::endl;
        std::cout << "2. Добавить несколько элементов в стек" << std::endl;
        std::cout << "3. Удалить элемент из стека" << std::endl;
        std::cout << "4. Вывести стек" << std::endl;
        std::cout << "5. Закончить работу программы" << std::endl;
        std::cout << "Что выбираете: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << "Введите добавляемый элемент: ";
            std::cin >> data;
            stack.push(data);
            break;
        case 2:
            int count;
            std::cout << "Введите кол-во добавляемых элементов: ";
            std::cin >> count;
            stack.pushMultiple(count);
            break;
        case 3:
            data = stack.pop();
            if (data != -1) {
                std::cout << "Удаленный элемент: " << data << std::endl;
            }
            break;
        case 4:
            stack.display();
            break;
        case 5:
            exit(0);
        default:
            std::cout << "Некорректный выбор!" << std::endl;
        }
    }
    return 0;
}