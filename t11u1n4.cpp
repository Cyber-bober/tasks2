/*� ����� input.txt ���������� �������� � ������ ��������� � ������� :
-����� ������;
-������ � ������ �������� ������ �������� ��������� �������� :
�������, ���, ��������, ��� ��������, ������ �� ���� ���������
���������� ������ ����� input.txt � ���� output.txt, ������������ �� �� �������� ����� ������ ������� �������(����� ������ ������� � ���� output.txt ��� ������� ��������); */

#include <iostream>
#include <fstream>
#include <sstream> // ��� ������������� stringstream
using namespace std;

// ��������� ��� �������� ������ � ��������
struct Student {
    string surname;      
    string name;        
    string patronymic;    
    int birthYear;        
    int grades[5];        
    int totalScore = 0;   // ����� ������ (���������������� �����)
};

// ������� ��� ���������� ��������� ������� �������
void insertionSort(Student* students, int count) {
    for (int i = 1; i < count; i++) { // �������� � ������� ��������
        int j = i;
        while (j > 0 && students[j - 1].totalScore < students[j].totalScore) {
            // ����� �������� ����� ��������� ����������
            Student temp = students[j];
            students[j] = students[j - 1];
            students[j - 1] = temp;
            j--; // ��������� � ����������� ��������
        }
    }
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    if (!in) {
        cout << "������: �� ������� ������� ���� input.txt" << endl;
        return 1;
    }

    if (!out) {
        cout << "������: �� ������� ������� ���� output.txt" << endl;
        return 1;
    }

    // ������ ������ ������
    string groupNumber;
    getline(in, groupNumber);

    // ������������ ������ ��� �������� ���������
    Student* students = nullptr;
    int studentCount = 0; // ������� ���������� ���������
    int capacity = 0;     // ������� ����������� �������

    // ������ ������ � ���������
    string line;
    while (getline(in, line)) {
        // ����������� ������ �������, ���� ����������
        if (studentCount == capacity) {
            capacity = (capacity == 0) ? 1 : capacity * 2; // ��������� �����������
            Student* newStudents = new Student[capacity];
            for (int i = 0; i < studentCount; i++) {
                newStudents[i] = students[i];
            }
            delete[] students; // ����������� ������ ������
            students = newStudents;
        }

        // ��������� ������ � ������� ������ stringstream
        stringstream ss(line);
        ss >> students[studentCount].surname;
        ss >> students[studentCount].name;
        ss >> students[studentCount].patronymic;
        ss >> students[studentCount].birthYear;

        // ������ ������ � ��������� �����
        students[studentCount].totalScore = 0;
        for (int i = 0; i < 5; i++) {
            ss >> students[studentCount].grades[i];
            students[studentCount].totalScore += students[studentCount].grades[i];
        }

        studentCount++; // ����������� ������� ���������
    }

    in.close();

    // ��������� ��������� �� �������� ����� ������
    insertionSort(students, studentCount);

    // ���������� ������ � output.txt
    out << groupNumber << endl;
    for (int i = 0; i < studentCount; i++) {
        out << students[i].surname << " "
            << students[i].name << " "
            << students[i].patronymic << " "
            << students[i].birthYear << " ";
        for (int j = 0; j < 5; j++) {
            out << students[i].grades[j] << " ";
        }
        out << students[i].totalScore << endl;
    }

    out.close();

    // ����������� ������
    delete[] students;

    cout << "������ ������� ���������� � �������� � ���� output.txt" << endl;

    return 0;
}