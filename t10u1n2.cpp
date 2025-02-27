#include <iostream>  
#include <cmath>     

using namespace std;

struct Point { // ��������� ��������� ��� �������� ��������� �����
    double x; 
    double y; 
};

const int MAX_POINTS = 5; // ������������ ���������� �����
int main() {
    setlocale(LC_ALL, "rus");
    int n; 
    cout << "������� ���������� �����: ";
    cin >> n;
    Point points[MAX_POINTS];  // ������� ������ �� n ��������� ���� Point
    if (n > MAX_POINTS) {
        cout << "���������� ����� ��������� ���������� ��������." << endl;
        return 0;
    }
    for (int i = 0; i < MAX_POINTS; i++) {
        cout << "������� ���������� ����� " << i + 1 << ": ";
        cin >> points[i].x >> points[i].y;
    }
    double maxDistance = 0; // ���������� ��� �������� ������������� ����������
    int indexMax = -1;      // ������ ����� � ������������ �����������

    for (int i = 0; i < MAX_POINTS; i++) { // ��������� ���������� �� ������ ��������� ��� ������ �����
        double distance = sqrt(points[i].x * points[i].x + points[i].y * points[i].y); 
        if (distance > maxDistance) { // ���� ������� ���������� ������ �������������
            maxDistance = distance; // ��������� ������������ ����������
            indexMax = i;           // ���������� ������ �����
        }
    }
    cout << "����� � ���������� ����������� �� ������ ���������: ("
        << points[indexMax].x << ", " << points[indexMax].y << ")" << endl;

    return 0;
}