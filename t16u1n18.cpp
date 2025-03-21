/*Дана последовательность целых чисел.
Поменять местами первый минимальный и последний элементы*/
#include <iostream> 
#include <vector>   
#include <algorithm> 

using namespace std; 

int main() {
    vector<int> numbers; 
    int n, value; 
    setlocale(LC_ALL, "RUS");

    cout << "Введите количество элементов: "; 
    cin >> n; 

    cout << "Введите элементы последовательности: "; 
    for (int i = 0; i < n; ++i) { 
        cin >> value; 
        numbers.push_back(value); 
    }

    if (numbers.empty()) { // Проверяем, не пустой ли вектор (если пользователь ввел n = 0)
        cout << "Последовательность пуста." << endl; 
        return 0;
    }

    // Находим первый минимальный элемент
    auto minIt = min_element(numbers.begin(), numbers.end()); // min_element возвращает итератор на минимальный элемент
    int minIndex = distance(numbers.begin(), minIt); // Вычисляем индекс минимального элемента

    // Индекс последнего элемента
    int lastIndex = numbers.size() - 1; 
    swap(numbers[minIndex], numbers[lastIndex]); 

    cout << "Измененная последовательность: "; 
    for (int num : numbers) { // Проходим по всем элементам вектора с помощью цикла for-each
        cout << num << " "; 
    }
    cout << endl; 

    return 0; 
}