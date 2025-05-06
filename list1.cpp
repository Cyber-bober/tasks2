/*Дана последовательность целых чисел. Подсчитать сумму элементов, расположенных
между максимальным и минимальным элементами (минимальный и максимальный элементы в массиве единственные).
Если минимальный элемент встречается позже максимального, то выдать сообщение об этом*/

#include <iostream>
#include <list>
using namespace std;

int main() {
    // Чтение входной последовательности
    int n;
    cout << "How many elements? ";
    cin >> n;

    list<int> lst;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        lst.push_back(num);
    }
    // Проверка, что список не пустой
    if (lst.empty()) {
        cout << "list pustoy\n";
        return 0;
    }
    // Найти минимальный и максимальный элементы
    list<int>::iterator minIter = lst.begin(), maxIter = lst.begin();
    for (list<int>::iterator iter = lst.begin(); iter != lst.end(); ++iter) {
        if (*iter < *minIter) minIter = iter;
        if (*iter > *maxIter) maxIter = iter;
    }
  
    if (distance(lst.begin(), minIter) > distance(lst.begin(), maxIter)) {
        cout << "Min element after max element\n";
        return 0;
    }
  
    int sum = 0;
    list<int>::iterator start = next(minIter); 
    list<int>::iterator end = maxIter;         

    while (start != end) {
        sum += *start;
        ++start;
    }

    cout << "sum of elements: " << sum << "\n";

    return 0;
}