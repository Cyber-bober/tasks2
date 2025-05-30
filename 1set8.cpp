//В текстовом файле даны целые числа, записанные через пробел. Найти все такие цифры, которые встречаются и в двухзначных и в трёхзначных числах
#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int main() {
    ifstream file("input.txt");
    if (!file) {
        cout << "Error opening file\n";
        return 1;
    }

    set<int> two;   
    set<int> three; 

    int num;
    while (file >> num) { 
        if (num >= 10 && num <= 99) { 
            two.insert(num % 10);   
            two.insert(num / 10);
        }
        else if (num >= 100 && num <= 999) { 
            three.insert(num % 10);    
            three.insert((num / 10) % 10); 
            three.insert(num / 100);     
        }
    }

    file.close();

    cout << "Common digits in both two-digit and three-digit numbers:\n";

    for (int digit : two) {
        if (three.find(digit) != three.end()) {
            cout << digit << " ";
        }
    }

    cout << endl;

    return 0;
}