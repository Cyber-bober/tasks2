#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    double x; 
    double y; 
    static int count; 

public:
    Point() : x(0), y(0) { count++;}  //без параметров
    
    Point(double x, double y) : x(x), y(y) {count++;} //с параметрами

    void display(const string& info = "") const {
        cout << "Point " << info << ": (" << x << ", " << y << ")" << endl;
    }
    static int getCount() {  
        return count;
    }

    double getX() const { return x; }
    double getY() const { return y; }

    double getDistanceToOrigin() const {
        return sqrt(x * x + y * y);
    }
// Перегрузка операторов сравнения
    bool operator<(const Point& other) const {
        return getDistanceToOrigin() < other.getDistanceToOrigin();
    }

    bool operator>(const Point& other) const {
        return getDistanceToOrigin() > other.getDistanceToOrigin();
    }

    bool operator==(const Point& other) const {
        return getDistanceToOrigin() == other.getDistanceToOrigin();
    }
};

int Point::count = 0; // Инициализация статического поля?!

int main() {
    Point pointA(3, 4); 
    Point pointB(6, 8); 
    Point pointC;       // (0, 0) 

    pointA.display("A");
    pointB.display("B");
    pointC.display("C");

    cout << "rastoynie to A: " << pointA.getDistanceToOrigin() << endl;
    cout << "rastoynie to B: " << pointB.getDistanceToOrigin() << endl;
    cout << "rastoynie to C: " << pointC.getDistanceToOrigin() << endl;

    // Сравнение точек
    if (pointA < pointB) {
        cout << "Point A blizhe than Point B." << endl;
    }
    else if (pointA > pointB) {
        cout << "Point A dalshe than Point B." << endl;
    }
    else {
        cout << "Point A and Point B ravnoudaleny" << endl;
    }

    cout << "kolichestvo tochek: " << Point::getCount() << endl;

    return 0;
}