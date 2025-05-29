//во входном файле задан набор слов и целых чисел, разделённых пробелами. Найти все слова, встречающиеся столько же раз, сколько последнее слово
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int main() {
    ifstream file("input.txt");
    if (!file) {
        cout << "Error opening file\n";
        return 1;
    }

    map<string, int> count; 
    string word, lastWord;

    while (file >> word) {
        count[word]++; 
        lastWord = word;  
    }
    file.close();

    if (count.empty()) {
        cout << "File is empty\n";
        return 0;
    }

    int lastWordCount = count[lastWord];
    cout << "Words that appear " << lastWordCount << " times:\n";
    for (const auto& pair : count) {
        if (pair.second == lastWordCount) {
            cout << pair.first << " ";
        }
    }
    cout << endl;

    return 0;
}