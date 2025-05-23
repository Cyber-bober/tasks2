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
        Element(Item x, Element* p = 0) : info(x), next(p) {}
    };
    Element* head = 0; 
    Element* tail = 0; 

public:
    Queue() : head(0), tail(0) {}

    bool Empty() {
        return head == 0;
    }

    Item Get() { // Извлечение элемента из очереди
        if (Empty()) {
            cout << "Queue is empty ";
            return 0;
        }
        Element* t = head;
        Item i = t->info;
        head = t->next;
        if (head == 0) {
            tail = 0;
        }
        delete t;
        return i;
    }

    void Put(Item data) { // Добавление элемента в очередь
        Element* t = new Element(data);
        if (head == 0) {
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
