#include <iostream>  
#include <cmath>     

using namespace std;

struct Point { // Определим структуру для хранения координат точки
    double x; 
    double y; 
};

const int MAX_POINTS = 5; // Максимальное количество точек
int main() {
    setlocale(LC_ALL, "rus");
    int n; 
    cout << "Введите количество точек: ";
    cin >> n;
    Point points[MAX_POINTS];  // Создаем массив из n элементов типа Point
    if (n > MAX_POINTS) {
        cout << "Количество точек превышает допустимое значение." << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cout << "Введите координаты точки " << i + 1 << ": ";
        cin >> points[i].x >> points[i].y;
    }
    double maxDistance = 0; // Переменная для хранения максимального расстояния
    int indexMax = -1;      // Индекс точки с максимальным расстоянием

    for (int i = 0; i < n; i++) { // Вычисляем расстояние до начала координат для каждой точки
        double distance = sqrt(points[i].x * points[i].x + points[i].y * points[i].y); 
        if (distance > maxDistance) { // Если текущее расстояние больше максимального
            maxDistance = distance; // Обновляем максимальное расстояние
            indexMax = i;           // Запоминаем индекс точки
        }
    }
    cout << "Точка с наибольшим расстоянием от начала координат: ("
        << points[indexMax].x << ", " << points[indexMax].y << ")" << endl;

    return 0;
}
