#include <iostream>
#include <fstream>
#include <list>
#include <queue>

using namespace std;

class Queue {
private:
    queue<int> data; 

public:
    void enqueue(int value) {
        data.push(value); 
    }

    int dequeue() {
        if (data.empty()) {
            return 0; 
        }
        int value = data.front(); 
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
        cout << "Error to open file\n"; 
        return 1; 
    }

    Queue positiveQueue; 
    Queue negativeQueue; 

    int num;
    while (file >> num) { 
        if (num >= 0) {
            positiveQueue.enqueue(num); 
        } else {
            negativeQueue.enqueue(num); 
        }
    }
    file.close(); 

    list<int> result;

    while (!positiveQueue.isEmpty()) {
        result.push_back(positiveQueue.dequeue()); 
    }

    while (!negativeQueue.isEmpty()) {
        result.push_back(negativeQueue.dequeue()); 
    }

    cout << "Resulting list: ";
    for (const auto& elem : result) {
        cout << elem << " "; 
    }
    cout << "\n"; 
    return 0; 
}