#include <fstream>
#include <queue>
using namespace std;

int main() {
	queue<int> t, w;  //t - numbers, w - '+' numbers 
	int chisla, sum = 0;

	ifstream go("numbers.txt");
	ofstream run("final.txt");

	while (go >> chisla) {
		t.push(chisla);
	}
	go.close();

	while (!t.empty()) {
		int num = t.front();
		if (num > 0) {
			w.push(num);  //+ numbers are writing 
			sum += num;
		}
		t.pop();
	}

	run << "+ numbers: \n";

	while (!w.empty()) {
		run << w.front() << " ";
		w.pop();
	}
	run << "\n\nsumma of + numbers: " << sum << "\n";
	run.close();
	return 0;
}