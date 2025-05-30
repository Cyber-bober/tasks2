#include <iostream> // ���������� ���������� ��� ������ � ������ � �������
#include <fstream>  // ���������� ���������� ��� ������ � �������
#include <string>   // ���������� ���������� ��� ������ �� ��������

using namespace std; // ���������� ����������� ������������ ����

int main() { // ������ ������� �������
    ifstream in("f.txt"); // ��������� ���� f ��� ������
    ofstream outNeg("g.txt"); // ��������� ���� g ��� ������ ������������� �����
    ofstream outPos("h.txt"); // ��������� ���� h ��� ������ ������������� �����

    if (!in) { // ���������, �������� �� ���� f
        cout << "Error opening file f"; // ���� ���, ������� ��������� �� ������
        return 1; // ���������� ��������� ��� ������
    }

    int number; // ��������� ���������� ��� �������� ���������� �����

    while (in >> number) { // ������ ����� �� ����� f
        if (number < 0) { // ���� ����� �������������
            outNeg << number << endl; // ���������� ��� � ���� g
        }
        else { // ���� ����� �������������
            outPos << number << endl; // ���������� ��� � ���� h
        }
    }

    in.close(); // ��������� ���� f
    outNeg.close(); // ��������� ���� g
    outPos.close(); // ��������� ���� h

    return 0; // ���������� 0, �������� ��������� �������
}