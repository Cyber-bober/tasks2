/*Дан список чисел в файле.В новый файл сперва записать положительные, а потом отрицательные числа*/
#include <iostream>
#include <fstream>
using namespace std;

template <class Item>
class Queue {
private:
    struct Element {
        Item info;
        Element* next;
        Element(Item x, Element* p = nullptr) : info(x), next(p) {}
    };
    Element* head = nullptr; // указатель на начало очереди
    Element* tail = nullptr; // указатель на конец очереди

public:
    Queue() : head(nullptr), tail(nullptr) {}

    bool Empty() {
        return head == nullptr;
    }

    Item Get() { // Извлечение элемента из очереди
        if (Empty()) {
            cout << "Queue is empty ";
            return 0;
        }
        Element* t = head;
        Item i = t->info;
        head = t->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete t;
        return i;
    }

    void Put(Item data) { // Добавление элемента в очередь
        Element* t = new Element(data);
        if (head == nullptr) {
            head = t;
            tail = t;
        }
        else {
            tail->next = t;
            tail = t;
        }
    }
};
int main() {
    ifstream file("input.txt");
    ofstream out("out.txt");
    Queue <int> positiveQueue, negativeQueue;
    int buf;

    if (!file) {
        cout << "Error opening file\n";
        return 1;
    }

    int num;
    while (file >> num) {
        if (num >= 0) {
            positiveQueue.Put(num);
        }
        else {
            negativeQueue.Put(num);
        }
    }
    file.close();

    while (!positiveQueue.Empty()) {
        int buf = positiveQueue.Get();
        out << buf << " ";
    }

    while (!negativeQueue.Empty()) {
        int buf = negativeQueue.Get();
        out << buf << " ";
    }

    return 0;
}