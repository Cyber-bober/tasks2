#include <iostream>  
#include <cmath>     

using namespace std;

struct Point { // ќпределим структуру дл€ хранени€ координат точки
    double x; 
    double y; 
};

const int MAX_POINTS = 5; // ћаксимальное количество точек
int main() {
    setlocale(LC_ALL, "rus");
    int n; 
    cout << "¬ведите количество точек: ";
    cin >> n;
    Point points[MAX_POINTS];  // —оздаем массив из n элементов типа Point
    if (n > MAX_POINTS) {
        cout << " оличество точек превышает допустимое значение." << endl;
        return 0;
    }
    for (int i = 0; i < MAX_POINTS; i++) {
        cout << "¬ведите координаты точки " << i + 1 << ": ";
        cin >> points[i].x >> points[i].y;
    }
    double maxDistance = 0; // ѕеременна€ дл€ хранени€ максимального рассто€ни€
    int indexMax = -1;      // »ндекс точки с максимальным рассто€нием

    for (int i = 0; i < MAX_POINTS; i++) { // ¬ычисл€ем рассто€ние до начала координат дл€ каждой точки
        double distance = sqrt(points[i].x * points[i].x + points[i].y * points[i].y); 
        if (distance > maxDistance) { // ≈сли текущее рассто€ние больше максимального
            maxDistance = distance; // ќбновл€ем максимальное рассто€ние
            indexMax = i;           // «апоминаем индекс точки
        }
    }
    cout << "“очка с наибольшим рассто€нием от начала координат: ("
        << points[indexMax].x << ", " << points[indexMax].y << ")" << endl;

    return 0;
}