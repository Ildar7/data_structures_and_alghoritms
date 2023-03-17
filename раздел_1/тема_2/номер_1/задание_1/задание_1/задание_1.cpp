#include <iostream>
#include <clocale>

const int MAX_SIZE = 10; // макс. размер стека

class Stack {
    private:
        int arr[MAX_SIZE];
        int top;

    public:
        Stack() {
            top = -1; // инициализация пустого стека
        }

        bool isEmpty() {
            return (top == -1);
        }

        bool isFull() {
            return (top == MAX_SIZE - 1);
        }

        void push(int data) {
            if (isFull()) {
                std::cout << "Стек переполнен, новые элементы добавить нельзя!" << std::endl;
                return;
            }
            top++;
            arr[top] = data;
        }

        int pop() {
            if (isEmpty()) {
                std::cout << "Стек пуст, нечего удалять!" << std::endl;
                return -1;
            }
            int data = arr[top];
            top--;
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