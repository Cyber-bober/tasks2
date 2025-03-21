/*дана последовательность целых чисел. Удалить из массива каждый k-й по счёту элемент*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers;
    int n, value, k;
    setlocale(LC_ALL, "RUS");

    cout << "Введите количество элементов: ";
    cin >> n;

    cout << "Введите элементы последовательности: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        numbers.push_back(value);
    }

    cout << "Введите значение k (каждый k-й элемент будет удален): ";
    cin >> k;

    if (k <= 0) {
        cout << "Значение k должно быть положительным." << endl;
        return 0;
    }
    if (numbers.empty()) {
        cout << "Последовательность пуста." << endl;
        return 0;
    }

    // Удаление каждого k-го элемента
    int index = k - 1; // Индекс первого удаляемого элемента
    while (index < numbers.size()) {
        numbers.erase(numbers.begin() + index); // Удаляем элемент по индексу
        index += k - 1; // Переходим к следующему k-му элементу
    }

    cout << "Измененная последовательность: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}