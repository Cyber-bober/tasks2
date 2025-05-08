#include <iostream>
#include <fstream>
#include <list>
#include <stack>

using namespace std;

class Stack {
private:
    stack <int> data;

public:
    void push(int value) {
        data.push(value);
    }

    int pop() {
        if (data.empty()) {
            cout << "Stack pustoy";
            return 0; 
        }
        int value = data.top();
        data.pop();
        return value;
    }

    bool isEmpty() const {
        return data.empty();
    }
};

int main() {
    ifstream file("input.txt"); 
    if (!file) {
        cout << "error to open file\n";
        return 1;
    }

    Stack positiveStack;
    Stack negativeStack;

    int num;
    while (file >> num) {
        if (num >= 0) {
            positiveStack.push(num);
        } else {
            negativeStack.push(num);
        }
    }

    file.close();

    list<int> result;
    while (!positiveStack.isEmpty()) {
        result.push_front(positiveStack.pop());
    }
    while (!negativeStack.isEmpty()) {
        result.push_front(negativeStack.pop());
    }
    cout << "Resulting list: ";
    for (const auto& elem : result) {
        cout << elem << " ";
    }
    return 0;
}