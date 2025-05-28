/*Дан список чисел в файле.В новый файл сперва записать положительные, а потом отрицательные числа*/
#include <iostream>
#include <fstream>
using namespace std;
class Stack {
    struct Element {
        int inf;
        Element* next;
        Element(int x, Element* p) : inf(x), next(p) {}
    };
    Element* head; 

public:
    Stack() : head(0) {}

    bool Empty() { 
        return head == 0;
    }

    int Pop() { 
        if (Empty()) {
            cout << "Stack is empty ";
            return 0;
        }
        Element* r = head; 
        int i = r->inf;   
        head = r->next;    
        delete r;         
        return i;         
    }

    void Push(int data) { 
        head = new Element(data, head);
    }

    int Top() { 
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

    Stack positiveTemp, negativeTemp;

    while (!positiveStack.Empty()) {
        positiveTemp.Push(positiveStack.Pop());
    }

    while (!negativeStack.Empty()) {
        negativeTemp.Push(negativeStack.Pop());
    }

    while (!positiveTemp.Empty()) {
        out << positiveTemp.Pop() << " ";
    }

    while (!negativeTemp.Empty()) {
        out << negativeTemp.Pop() << " ";
    }

    return 0;
}
