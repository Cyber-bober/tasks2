/*���� ������������������ ����� �����.
�������� ������� ������ ����������� � ��������� ��������*/
#include <iostream> 
#include <vector>   
#include <algorithm> 

using namespace std; 

int main() {
    vector<int> numbers; 
    int n, value; 
    setlocale(LC_ALL, "RUS");

    cout << "������� ���������� ���������: "; 
    cin >> n; 

    cout << "������� �������� ������������������: "; 
    for (int i = 0; i < n; ++i) { 
        cin >> value; 
        numbers.push_back(value); 
    }

    if (numbers.empty()) { // ���������, �� ������ �� ������ (���� ������������ ���� n = 0)
        cout << "������������������ �����." << endl; 
        return 0;
    }

    // ������� ������ ����������� �������
    auto minIt = min_element(numbers.begin(), numbers.end()); // min_element ���������� �������� �� ����������� �������
    int minIndex = distance(numbers.begin(), minIt); // ��������� ������ ������������ ��������

    // ������ ���������� ��������
    int lastIndex = numbers.size() - 1; 
    swap(numbers[minIndex], numbers[lastIndex]); 

    cout << "���������� ������������������: "; 
    for (int num : numbers) { // �������� �� ���� ��������� ������� � ������� ����� for-each
        cout << num << " "; 
    }
    cout << endl; 

    return 0; 
}