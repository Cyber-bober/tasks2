#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
	ofstream out("f.bin", ios::binary); //для записи
	for (int i = 0; i < 10; i++) {  //генереция степеней
		int power = (pow(3, i));
		out.write((char*)&power, sizeof(power)); //запись степени в файл
	}
	out.close();
	ifstream in("f.bin", ios::binary); //для чтения
	if (!in) {
		cout << "error" << endl;
		return 1;
	}
	int power;
	for (int index = 0; index < 10; ++index) {
		in.read((char*)&power, sizeof(power));
		cout << "power of 3 in posiion " << index << ": " << power << endl; 
		in.seekg(sizeof(power), ios::cur); //cur - перемещение указателя относительно текущей позиции
		index++;
	}

	in.close();
	return 0;
}
