/*���� ������������������ ����� �����. ������� �� ������� ������ k-� �� ����� �������*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers;
    int n, value, k;
    setlocale(LC_ALL, "RUS");

    cout << "������� ���������� ���������: ";
    cin >> n;

    cout << "������� �������� ������������������: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        numbers.push_back(value);
    }

    cout << "������� �������� k (������ k-� ������� ����� ������): ";
    cin >> k;

    if (k <= 0) {
        cout << "�������� k ������ ���� �������������." << endl;
        return 0;
    }
    if (numbers.empty()) {
        cout << "������������������ �����." << endl;
        return 0;
    }

    // �������� ������� k-�� ��������
    int index = k - 1; // ������ ������� ���������� ��������
    while (index < numbers.size()) {
        numbers.erase(numbers.begin() + index); // ������� ������� �� �������
        index += k - 1; // ��������� � ���������� k-�� ��������
    }

    cout << "���������� ������������������: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}