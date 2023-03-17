#include <iostream>
#include <clocale>

class Queue {
    private:
        int* queue; // Указатель на массив для хранения элементов очереди
        int front; // Индекс переднего элемента очереди
        int rear; // Индекс заднего элемента очереди
        int size; // Размер очереди
    public:
        Queue(int size = 10) { // Конструктор для инициализации очереди
            this->size = size;
            queue = new int[size];
            front = -1;
            rear = -1;
        }
        ~Queue() { // Деструктор для освобождения динамически выделенной памяти
            delete[] queue;
        }
        bool isEmpty() { // Проверка на пустоту очереди
            return front == -1;
        }
        void enqueue(int item) { // Добавьте элемент в конец очереди
            if (front == -1) { // Если очередь пуста
                front = 0;
            }
            rear++;
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
                front++;
            }
            std::cout << "Убрал " << item << " из очереди." << std::endl;
        }
        void display() { // Отображение текущего состояния очереди
            if (isEmpty()) {
                std::cout << "Очередь пуста." << std::endl;
                return;
            }
            std::cout << "Текущее состояние очереди: ";
            for (int i = front; i <= rear; i++) {
                std::cout << queue[i] << " ";
            }
            std::cout << std::endl;
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
            std::cout << "Текущее состояние очереди: ";
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