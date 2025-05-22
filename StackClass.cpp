/*ƒан список чисел в файле.¬ новый файл сперва записать положительные, а потом отрицательные числа*/
#include <iostream>
#include <fstream>
using namespace std;
class Stack {
    struct Element {
        int inf;
        Element* next;
        Element(int x, Element* p) : inf(x), next(p) {}
    };
    Element* head; // указатель на вершину стека

public:
    Stack() : head(0) {} // конструктор стека

    bool Empty() { // проверка на пустоту
        return head == 0;
    }

    int Pop() { // извлечение элемента из стека
        if (Empty()) {
            cout << "Stack is empty ";
            return 0;
        }
        Element* r = head; // запоминаем указатель на верхний элемент
        int i = r->inf;   // запоминаем информацию из верхнего элемента
        head = r->next;    // передвигаем указатель на следующий от вершины элемент
        delete r;          // освобождаем пам€ть, на которую указывает r
        return i;          // возвращаем значение информационного пол€
    }

    void Push(int data) { // добавление элемента в стек
        head = new Element(data, head);
    }

    int Top() { // просмотр элемента на вершине
        if (Empty()) {
            cout << "Stack is empty ";
            return 0;
        }
        return head->inf;
    }
};
int main() {
    ifstream file("input.txt");
    ofstream out("out.txt");
    Stack positiveStack, negativeStack;
    int buf;

    if (!file) {
        cout << "Error opening file\n";
        return 1;
    }

    int num;
    while (file >> num) {
        if (num >= 0) {
            positiveStack.Push(num);
        }
        else {
            negativeStack.Push(num);
        }
    }
    file.close();

    while (!positiveStack.Empty()) {
        int buf = positiveStack.Pop();
        out << buf << " ";
    }

    // ƒобавление отрицательных чисел
    while (!negativeStack.Empty()) {
        int buf = negativeStack.Pop();
        out << buf << " ";
    }

    return 0;
}