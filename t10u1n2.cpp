#include <iostream>  
#include <cmath>     
#include <fstream>   // для работы с файлами

using namespace std;

struct Point {
    double x;
    double y;
};

const int MAX_POINTS = 5;

int main() {
    setlocale(LC_ALL, "rus");

    // Открываем файл для чтения
    ifstream in("input.txt");
    if (!in.is_open()) {
        cout << "Ошибка" << endl;
        return 1;
    }

    int n;
    in >> n; // Читаем количество точек из файла

    if (n > MAX_POINTS) {
        cout << "Количество точек превышает допустимое значение." << endl;
        return 0;
    }

    Point points[MAX_POINTS];

    // Читаем координаты точек из файла
    for (int i = 0; i < n; i++) {
        in >> points[i].x >> points[i].y;
    }

    double maxDistance = 0;
    int indexMax = -1;

    for (int i = 0; i < n; i++) {
        double distance = sqrt(points[i].x * points[i].x + points[i].y * points[i].y);
        if (distance > maxDistance) {
            maxDistance = distance;
            indexMax = i;
        }
    }

    cout << "Точка с наибольшим расстоянием от начала координат: ("
        << points[indexMax].x << ", " << points[indexMax].y << ")" << endl;

    return 0;
}
