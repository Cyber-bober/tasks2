/*Дана последовательность целых чисел. Подсчитать сумму элементов, расположенных
между максимальным и минимальным элементами (минимальный и максимальный элементы в массиве единственные).
Если минимальный элемент встречается позже максимального, то выдать сообщение об этом*/

#include <iostream>
#include <list>
using namespace std;

int main() {
    int n;
    cout << "How many elements? ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of elements can't be 0\n";
        return 0;
    }

    list<int> lst;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        lst.push_back(num);
    }

    if (lst.empty()) {
        cout << "List is empty\n";
        return 0;
    }

    auto minIter = lst.begin();
    auto maxIter = lst.begin();

    for (auto iter = lst.begin(); iter != lst.end(); ++iter) {
        if (*iter < *minIter) minIter = iter;
        if (*iter > *maxIter) maxIter = iter;
    }

    bool minAfterMax = distance(lst.begin(), minIter) > distance(lst.begin(), maxIter);

    if (minAfterMax) {
        cout << "Min element after max element\n";
    }

    if (minAfterMax) {
        swap(minIter, maxIter);  //for sum
    }

    int sum = 0;
    for (auto iter = next(minIter); iter != maxIter; ++iter) {
        sum += *iter;
    }

    cout << "Sum of elements between min and max: " << sum << "\n";

    return 0;
}