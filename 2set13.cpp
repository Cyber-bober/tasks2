//В текстовом файле дано несколько строк, состоящих из латинских букв, цифр, знаков препинания и пробелов.
//Для каждой строки вывести буквы, которых в строке нет
#include <iostream>
#include <fstream>
#include <set>
#include <string>
using namespace std;

int main() {
    ifstream file("input.txt");
    if (!file) {
        cout << "Error opening file\n";
        return 1;
    }

    set<char> allLetters = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                            'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

    string line;

    while (getline(file, line)) { 
        set<char> Letters; 

        for (char c : line) {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                Letters.insert(c); 
            }
        }

        cout << "Missing letters in this line:\n";
        for (char c : allLetters) {
            if (Letters.find(c) == Letters.end()) {
                cout << c << " ";
            }
        }
        cout << endl;
    }

    file.close();
    return 0;
}
