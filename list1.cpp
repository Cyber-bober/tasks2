/*���� ������������������ ����� �����. ���������� ����� ���������, �������������
����� ������������ � ����������� ���������� (����������� � ������������ �������� � ������� ������������).
���� ����������� ������� ����������� ����� �������������, �� ������ ��������� �� ����*/

#include <iostream>
#include <list>
using namespace std;

int main() {
    // ������ ������� ������������������
    int n;
    cout << "How many elements? ";
    cin >> n;

    list<int> lst;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        lst.push_back(num);
    }
    // ��������, ��� ������ �� ������
    if (lst.empty()) {
        cout << "list pustoy\n";
        return 0;
    }
    // ����� ����������� � ������������ ��������
    list<int>::iterator minIter = lst.begin(), maxIter = lst.begin();
    for (list<int>::iterator iter = lst.begin(); iter != lst.end(); ++iter) {
        if (*iter < *minIter) minIter = iter;
        if (*iter > *maxIter) maxIter = iter;
    }
  
    if (distance(lst.begin(), minIter) > distance(lst.begin(), maxIter)) {
        cout << "Min element after max element\n";
        return 0;
    }
  
    int sum = 0;
    list<int>::iterator start = next(minIter); 
    list<int>::iterator end = maxIter;         

    while (start != end) {
        sum += *start;
        ++start;
    }

    cout << "sum of elements: " << sum << "\n";

    return 0;
}