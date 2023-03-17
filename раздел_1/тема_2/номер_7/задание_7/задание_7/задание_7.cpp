#include <iostream>
#include <clocale>
#include <cstdlib>
#include <ctime>

class Queue {
private:
    char* queue; // Указатель на массив для хранения элементов очереди
    int front; // Индекс переднего элемента очереди
    int rear; // Индекс заднего элемента очереди
    int size; // Размер очереди
public:
    Queue(int size = 10) { // Конструктор для инициализации очереди
        this->size = size;
        queue = new char[size];
        front = -1;
        rear = -1;
    }
    ~Queue() { // Деструктор для освобождения динамически выделенной памяти
        delete[] queue;
    }
    bool isEmpty() { // Проверка на пустоту очереди
        return front == -1;
    }
    void enqueue(char item) { // Добавить элемент в конец очереди
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
        char item = queue[front];
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

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));	// Инициализируем генератор случайных чисел текущим временем
    Queue q;	// Создаем пустую очередь
    std::cout << "Начало моделирования очереди." << std::endl;
    char choice;
    do {
        int num = rand() % 100 + 1;	// Генерируем случайное число от 1 до 100
        if (num % 2 == 0)
        {
            // Если число четное, добавляем элементы в очередь
            int n = rand() % 3 + 1;	// Генерируем случайное число от 1 до 3
            std::cout << "Добавляем " << n << " элементов в очередь." << std::endl;
            for (int i = 0; i < n; i++)
            {
                char c = rand() % 26 + 65;	// Генерируем случайную заглавную букву (код ASCII 65-90)
                q.enqueue(c);
            }
        }
        else
        {
            // Если число нечетное, удаляем элементы из очереди
            int n = rand() % 3 + 1;	// Генерируем случайное число от 1 до 3
            std::cout << "Удаляем " << n << " элементов из очереди." << std::endl;
            for (int i = 0; i < n; i++)
            {
                if (!q.isEmpty())
                {
                    q.dequeue();
                }
                else
                {
                    std::cout << "Очередь пуста, больше нельзя удалять элементы." << std::endl;
                    break;
                }
            }
        }

        q.display();	// Отображаем текущее состояние очереди
        std::cout << "Нажмите q для выхода, или любую другую клавишу для продолжения: ";
        std::cin >> choice;
    } while (choice != 'q');
    std::cout << "Моделирование очереди завершено." << std::endl;
    return 0;
}