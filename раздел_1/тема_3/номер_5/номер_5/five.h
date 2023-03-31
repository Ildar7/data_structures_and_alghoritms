#ifndef DATA_PROCESSING_STRUCTURES_AND_ALGORITHMS_FIVE_H
#define DATA_PROCESSING_STRUCTURES_AND_ALGORITHMS_FIVE_H

#include <iostream>
#include <string>
#include <clocale>


using namespace std;
int counter = 0;

struct List {
    string value;//�������������� ����� ��������
    List* next;//��������� ���������� ���������
}*head, * stackhead;//head -��������� ������, secondhead- ������� ���������������� �����

void initList() {//������������� �������� ������
    head = new List();//���������
    head->next = NULL;//��������� � �������� ������� ���������
}

void initStack() { //������������� ���������������� �����
    stackhead = new List();
    stackhead->next = NULL;
}
//�������� ������� ������ � �����
bool isListEmpty() {
    if (head->next == NULL) return 1;
    else return 0;
}

bool isStackEmpty() {
    if (stackhead->next == NULL) return 1;
    else return 0;
}
//����� ��������� ������
void showList() {
    if (!isListEmpty()) {
        int i = 1;
        List* current;//���� ��������������� ����������

        current = head->next;//��������� � ����� ������� ��������
        while (current != NULL) {
            cout << i << ") " << current->value << "\n";
            current = current->next;
            i++;
        }
    }
    else cout << "\n������ ����.\n";
}
//����������� ������� ��� �����
void showStack() {
    if (!isStackEmpty()) {
        int i = 1;
        List* current;//���� ��������������� ����������
        current = stackhead->next;//��������� � ����� ������� ��������
        while (current != NULL) {
            cout << i << ")" << current->value << "\n";
            current = current->next;
            i++;
        }
    }
    else cout << "\n���� ����.\n";
}

void before() {
    string _value;
    string __value;
    List* current = NULL;//������������������������  ���������
    List* temp = new List;//��������������� �������� ��������� ��� ������ ������������ ��������
    cout << "\n������� �������, ����� ������� �� ������ ��������: ";
    showList();cin.clear(); cin.ignore(32767, '\n'); getline(cin, _value);

    List* pred;//���� ��������������� �������� ����������(�������������� current)
    pred = head;//��������� � ��������� ( current ���� � ������� ��������� ��������)
    current = head->next;//��������� current � ����� ������� ��������� ��������
    while (current != NULL) {
        if (current->value == _value) break;
        current = current->next;
        pred = pred->next;
    }
    temp->next = current;//����� ���� ��� ��������(��������� �����)
    pred->next = temp;//��������� ��������� ����� �������� �������������� �� ����� ������ ��������
    cout << "\n������� ��������: "; cin.clear(); getline(cin, __value);
    cout << "\n������� ��������\n"; temp->value = __value;
}
void after() {
    string _value, __value;
    List* current = NULL;//������������������������  ���������
    List* temp = new List;//��������������� �������� ��������� ��� ������ ������������ ��������
    current = head->next;
    cout << "\n������� �������, ����� �������� �� ������ ��������: ";
    showList(); cin.clear(); cin.ignore(32767, '\n'); getline(cin, _value);
    while ((current != NULL) && (current->value != _value)) {
        if (current->value == _value) break;
        current = current->next;
    }
    temp->next = current->next;//����� ���� ��� ��������� �����
    current->next = temp;//��������� ��������� ����� ������ �������� �� ����� ������ ��������
    cout << "\n������� ��������: "; //cin.clear();
    cin >> __value;
    //cin.ignore(32767, '\n'); getline(cin, __value);
    cout << "\n������� ��������\n"; temp->value = __value;
}

void Push() {
    string _value;
    if (counter == 0) {
        cout << "\n������� �������: ";
        cin.clear(); cin.ignore(32767, '\n'); getline(cin, _value);
        List* temp = new List();
        temp->value = _value;
        temp->next = NULL;
        head->next = temp;
        counter++;
        cout << "\n������� ��������\n";
    }
    else {
        int choice;
        cout << "\n���� �������� �������?\n0 - ��\n1 - �����";
        cout << "\n�������� ��������: ";
        cin >> choice;
        if (choice == 0) {
            before();
        }
        else if (choice == 1) {
            after();
        }
        else cout << "\n������. ������� '1' ��� '0'\n";
    }
}
void pop() {
    if (!isListEmpty()) {
        string _value;
        List* current;//���� ��������������� ��������� ����������
        List* pred;//��� ���� ���������������, �������������� curernt
        current = head->next;//��������� current  � ����� ������� ��������
        pred = head;//��������� pred  � ���������
        int choice = -1;
        int i = -1;
        while ((choice != 1) && (choice != 0)) {
            cout << "\n��� �� ������ �������:\n0 - ������� ���������\n1 - ������� �� ��������������� ����";
            cout << "\n�������� ��������: ";
            cin >> choice;
            showList();

            while (i == -1) {
                cout << "\n������� �������, ������� �� ������ �������: "; cin.clear(); cin.ignore(32767, '\n'); getline(cin, _value);
                while (current != NULL) {
                    if (current->value == _value) break;
                    current = current->next;
                    pred = pred->next;
                }
                if (current != NULL) {
                    i++;
                    cout << "\n������� " << _value << " ������\n";
                }
                else cout << "\n������� �� ������\n";
            }
            if (choice == 0) {
                pred->next = current->next;//��������� ��������� ����� �������� ��������������� �� ��������� ����� ���������� ��������
                delete current;
                cout << "\n������� " << current->value << " ��� ������\n";
            }
            else if (choice == 1) {
                pred->next = current->next;// � �������� ������ ��������� ��������� ����� �������� ��������������� �� ��������� ����� ���������� ��������
                List* temp = current;//���� ��������������� ��������� ��������� ��� ������ �������� � �����
                temp->next = stackhead->next;
                stackhead->next = temp;
                cout << "\n������� " << current->value << " ��� ������ �� ��������������� ����\n";
            }
            else {
                cout << "\n������. ���������� ������� ���������� �����\n";
            }
        }
    }
    else cout << "\n������. ������ ����\n";
}

void find() {
    if (!isListEmpty()) {
        showList();
        string _value;
        cout << "\n������� �������, ������� �� ������ �����: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin, _value);
        int i = 1;
        List* current;
        current = head->next;
        while ((current != NULL) && (current->value != _value)) {
            current = current->next;
            i++;
        }
        if (current != NULL) cout << "\n�������" << _value << " ������. ��� �����:" << i << "\n";
        else cout << "\n�������" << _value << " �� ������\n";
    }
    else cout << "\n������ ����. ������ ������.\n";
}

//������� ������ ����� ����������� ������ ��������� (������������ ������)
inline void ClearList() {
    List* current; //���� ��������������� ��������� ����������
    while (head != NULL) { //����������� ������, ������� ��� �������� ������
        current = head;
        head = head->next;
        delete current;
    }
    initList(); //��������� �����������, �������� ������� ������
}
//������� ���������������� ����� ����� ����������� ������ ��������� (������������ ������)
inline void ClearStack() {
    List* current; //���� ��������������� ��������� ����������
    while (stackhead != NULL) { //����������� ������, ������� ��� ��������������� ������ (����)
        current = stackhead;
        stackhead = stackhead->next;
        delete current;
    }
    initStack(); //��������� �����������, �������� ������� ���������������� �����
}


#endif //DATA_PROCESSING_STRUCTURES_AND_ALGORITHMS_FIVE_H
