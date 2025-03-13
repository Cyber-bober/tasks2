/*дана матрица размерностью n*n, содержащая целые числа.
Отсортировать диагонали матрицы параллельные побочной по возрастанию элементов методом пузырька*/
#include <iostream>
#include <fstream>
using namespace std;

// Функция для сортировки массива методом пузырька
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // Оптимизация: если за проход не было обменов, массив уже отсортирован
    }
}

int main() {
    // Открываем входной и выходной файлы
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл input.txt" << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл output.txt" << endl;
        return 1;
    }

    int n;
    inputFile >> n; // Считываем размер матрицы

    // Динамическое выделение памяти для матрицы
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }

    // Заполнение матрицы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inputFile >> matrix[i][j];
        }
    }

    // Временный массив для хранения элементов диагонали
    int* tempArray = new int[n]; // Максимальный размер диагонали равен n

    // Сортировка диагоналей выше побочной диагонали
    for (int k = 0; k < n - 1; k++) { // k — номер диагонали выше побочной
        int size = n - k - 1; // Размер текущей диагонали
        for (int i = 0; i < size; i++) {
            tempArray[i] = matrix[i][n - k - 2 - i]; // Сбор элементов диагонали
        }

        // Сортировка элементов диагонали
        bubbleSort(tempArray, size);

        // Возвращение отсортированных элементов в матрицу
        for (int i = 0; i < size; i++) {
            matrix[i][n - k - 2 - i] = tempArray[i];
        }
    }

    // Сортировка диагоналей ниже побочной диагонали
    for (int k = 0; k < n - 1; k++) { // k — номер диагонали ниже побочной
        int size = n - k - 1; // Размер текущей диагонали
        for (int i = 0; i < size; i++) {
            tempArray[i] = matrix[k + 1 + i][n - 1 - i]; // Сбор элементов диагонали
        }

        // Сортировка элементов диагонали
        bubbleSort(tempArray, size);

        // Возвращение отсортированных элементов в матрицу
        for (int i = 0; i < size; i++) {
            matrix[k + 1 + i][n - 1 - i] = tempArray[i];
        }
    }

    // Запись отсортированной матрицы в выходной файл
    outputFile << "Отсортированная матрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            outputFile << matrix[i][j] << " ";
        }
        outputFile << endl;
    }

    // Освобождение памяти
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] tempArray;

    // Закрытие файлов
    inputFile.close();
    outputFile.close();

    cout << "Данные успешно обработаны и записаны в файл output.txt" << endl;

    return 0;
}
