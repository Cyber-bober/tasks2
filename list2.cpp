/*Дана последовательность целых чисел. Удалить из массива 
повторяющиеся элементы, оставив только их первые вхождения*/
#include <iostream> 
#include <list>
using namespace std;

int main(){
    int n = 0;
    cout << "Numbers of element: ";
    cin >> n;
    if (n < 0) {
        cout << "Numbers can't be 0\n";
        return 0;
    }
    list <int> lst;
    int num = 0;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> num;
        lst.push_back(num);
    }
     if (lst.empty()) {
        cout << "List is empty\n";
        return 0;
    }
    
   for (auto iter = lst.begin(); iter != lst.end(); ++iter) {
        auto povIter = next(iter);
        while (povIter != lst.end()) {
            if (*povIter == *iter) {
                povIter = lst.erase(povIter);
            } else {
                ++povIter; 
            }
        }
    }
    cout << "Elements after delete povtoreniy: ";
    for (const auto& elem : lst) {
        cout << elem << " ";
    }
    return 0;
}