#include <iostream> // ���������� ���������� ��� ������ � ������/�������
#include <fstream>  // ���������� ���������� ��� ������ � �������

using namespace std;

int main() {
    ofstream out("powers_of_three.bin", ios::binary); // ��������� �������� ���� ��� ������

    for (int i = 0; i < 10; ++i) { // ���� ��� ������ ������ 10 �������� ����� 3
        int power = static_cast<int>(pow(3, i)); // ��������� ������� ����� 3
        out.write(reinterpret_cast<const char*>(&power), sizeof(power)); // ���������� ������� � ����
    }

    out.close(); // ��������� ���� ����� ������

    ifstream in("powers_of_three.bin", ios::binary); // ��������� �������� ���� ��� ������
    if (!in) { // ���������, �������� �� ����
        cerr << "������ �������� �����." << endl; // ������� ��������� �� ������
        return 1; // ��������� ��������� � ����� ������
    }

    int power; // ���������� ��� ������ �������� �� �����
    int index = 0; // ������ ��� ������������ ����������� ������

    while (in.read(reinterpret_cast<char*>(&power), sizeof(power))) { // ������ ������ �� �����
        if (index % 2 == 0) { // ���������, ������ �� ���������� �����
            cout << "������� 3 � ������� " << index << ": " << power << endl; // ������� ������� �� �����
        }
        index++; // ����������� ���������� �����
    }

    in.close(); // ��������� ���� ����� ������
    return 0; // ��������� ��������� �������
}