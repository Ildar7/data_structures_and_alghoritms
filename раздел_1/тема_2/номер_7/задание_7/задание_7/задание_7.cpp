#include "config.h"

char fail() {
    char a;
    while (!(cin >> a) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Ошибка попробуйте снова" << endl;
    }
    return a;
}

int getRandom(int maxValue) {
    return(rand() % maxValue) + 1;
}

void RandomAction() {
    int randomAction = getRandom(100);
    int randomCount = getRandom(maxElementToAction);
    bool isPush = randomAction % 2 == 0;
    cout << "Действие" << (isPush ? " Добавление " : " Удаление") << "\nНомер элемента: " << randomCount << endl;
    if (isPush) {
        for (int i = 0; i < randomCount; i++) {
            char symbol = symbols[getRandom(25)];
            push(symbol);
            cout << "Добавление: [" << symbol << "]" << endl;
        }

    }
    else {
        for (int i = 0; i < randomCount; i++) {
            if (!isEmpty()) {
                cout << "Удаление: [" << pop() << "]" << endl;
            }
            else {
                break;
            }
        }
    }
    ShowQueue();
}

void start() {
    srand(time(NULL));
    char q;
    while (true) {
        RandomAction();
        q = fail();
        if (q == 'q') {
            break;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    initQueue();
    start();
    return 0;
}