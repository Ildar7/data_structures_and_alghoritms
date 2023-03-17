#include <iostream>
#include <clocale>
#include <cstdlib>
#include <ctime>
#include <stack>

class Stack {

    public:
        std::stack<int> mainStack;
        std::stack<int> deletedStack;

        bool isEmpty() {
            return mainStack.empty();
        }

        void push(int data) {
            mainStack.push(data);
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
            int data = mainStack.top();
            mainStack.pop();
            return data;
        }

        void deleteElement() {
            int popChoice;
            std::cout << "Выберите действие с удаленным элементом:" << std::endl;
            std::cout << "1. Удалить с освобождением памяти" << std::endl;
            std::cout << "2. Добавить в стек удаленных элементов" << std::endl;
            std::cin >> popChoice;
            if (popChoice == 1) {
                mainStack.pop();
            }
            else if (popChoice == 2) {
                int poppedValue = mainStack.top();
                mainStack.pop();
                deletedStack.push(poppedValue);
            }
        }

        void display() {
            if (isEmpty()) {
                std::cout << "Стек пуст" << std::endl;
                return;
            }
            std::cout << "Элементы стека: ";
            std::stack<int> tmpStack;
            while (!mainStack.empty()) {
                tmpStack.push(mainStack.top());
                mainStack.pop();
            }
            while (!tmpStack.empty()) {
                std::cout << tmpStack.top() << " ";
                mainStack.push(tmpStack.top());
                tmpStack.pop();
            }
            std::cout << std::endl;
        }

        void displayDeleted() {
            if (deletedStack.empty()) {
                std::cout << "Стек удаленных элементов пуст" << std::endl;
                return;
            }
            std::cout << "Элементы стека удаленных элементов: ";
            std::stack<int> tmpStack;
            while (!deletedStack.empty()) {
                tmpStack.push(deletedStack.top());
                deletedStack.pop();
            }
            while (!tmpStack.empty()) {
                std::cout << tmpStack.top() << " ";
                deletedStack.push(tmpStack.top());
                tmpStack.pop();
            }
            std::cout << std::endl;
        }

        int size() {
            return mainStack.size();
        }
};

int main() {
    setlocale(LC_ALL, "Russian");
    std::srand(std::time(nullptr));
    Stack stack;
    int choice;

    while (true) {
        std::cout << "1. Добавить элемент" << std::endl;
        std::cout << "2. Добавить несколько элементов в стек" << std::endl;
        std::cout << "3. Удалить элемент" << std::endl;
        std::cout << "4. Вывести содержимое стека" << std::endl;
        std::cout << "5. Вывести содержимое стека удаленных элементов" << std::endl;
        std::cout << "6. Выйти" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1:
            int data, originChoice;

            std::cout << "Выберите происхождение элемента:" << std::endl;
            std::cout << "1. Создать новый элемент" << std::endl;
            std::cout << "2. Выбрать из стека удаленных элементов" << std::endl;
            std::cin >> originChoice;
            if (originChoice == 2 && !stack.deletedStack.empty()) {
                // берем верхний элемент из удаленного стека и помещаем его в основной стек
                data = stack.deletedStack.top();
                stack.deletedStack.pop();
                stack.mainStack.push(data); // добавляем элемент в основной стек
            }
            else {
                std::cout << "Введите значение нового элемента: ";
                std::cin >> data;
                stack.push(data);
            }
            break;
        case 2:
            int count;
            std::cout << "Введите кол-во добавляемых элементов: ";
            std::cin >> count;
            stack.pushMultiple(count);
            break;
        case 3:
            if (stack.isEmpty()) {
                std::cout << "Стек пуст, нечего удалять!" << std::endl;
            }
            else {
                stack.deleteElement();
            }
            break;
        case 4:
            stack.display();
            break;
        case 5:
            stack.displayDeleted();
            break;
        case 6:
            exit(0);
        default:
            std::cout << "Некорректный выбор!" << std::endl;
            break;
        }
    }

    return 0;
}