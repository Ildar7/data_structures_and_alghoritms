#include <iostream>
#include <clocale>

const int MAX_SIZE = 10; // Максимальный размер очереди

class Queue {
    private:
        int queue[MAX_SIZE]; // Массив для хранения элементов очереди
        int front; // Индекс переднего элемента очереди
        int rear; // Индекс заднего элемента очереди
    public:
        Queue() { // Конструктор для инициализации очереди
            front = -1;
            rear = -1;
        }
        bool isEmpty() { // Проверка на пустоту очереди
            return front == -1;
        }
        bool isFull() { // Проверка на полноту очереди
            return (front == 0 && rear == MAX_SIZE - 1) || (rear == front - 1);
        }
        void enqueue(int item) { // Добавьте элемент в конец очереди
            if (isFull()) {
                std::cout << "Очередь заполнена, не удается поставить в очередь." << std::endl;
                return;
            }
            if (front == -1) { // Если очередь пуста
                front = 0;
            }
            rear = (rear + 1) % MAX_SIZE;
            queue[rear] = item;
            std::cout << "Добавил " << item << " в очередь." << std::endl;
        }
        void dequeue() { // Удалить элемент из начала очереди
            if (isEmpty()) {
                std::cout << "Очередь пуста, не может быть снята с очереди." << std::endl;
                return;
            }
            int item = queue[front];
            if (front == rear) { // Если в очереди есть только один элемент
                front = -1;
                rear = -1;
            }
            else {
                front = (front + 1) % MAX_SIZE;
            }
            std::cout << "Убрал " << item << " из очереди." << std::endl;
        }
        void display() { // Отображение текущего состояния очереди
            if (isEmpty()) {
                std::cout << "Очередь пуста." << std::endl;
                return;
            }
            std::cout << "Текущее состояние очереди: ";
            int i = front;
            while (i != rear) {
                std::cout << queue[i] << " ";
                i = (i + 1) % MAX_SIZE;
            }
            std::cout << queue[rear] << std::endl;
        }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Queue q; // Инициализировать пустую очередь
    int choice, item;
    do { // Цикл диалога с пользователем
        std::cout << "1. Добавить в очередь" << std::endl;
        std::cout << "2. Удалить из очереди" << std::endl;
        std::cout << "3. Показать очередь" << std::endl;
        std::cout << "4. Закончить работу программы" << std::endl;
        std::cout << "Введите свой выбор: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << "Введите элемент для добавления в очередь: ";
            std::cin >> item;
            q.enqueue(item);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            std::cout << "Текущая очередь: ";
            q.display();
            break;
        case 4:
            exit(0);
        default:
            std::cout << "Неверный выбор, пожалуйста, попробуйте еще раз." << std::endl;
        }
    } while (choice != 4);
    return 0;
}