#include <fstream>
#include <stack>
using namespace std;

int main() {
	stack<int> t, t1, w;  //t - numbers, t1 - '+' numbers, w - '+' numbers dopolnenie
	int chisla, sum = 0;

	ifstream go("numbers.txt");
	ofstream run("final.txt");

	while (go >> chisla) {
		t.push(chisla);
		if (chisla > 0) {
			t1.push(chisla);
		}
	}
	go.close();

	while (!t1.empty()) {
		int num = t1.top();
		sum += num;
		w.push(num);
		t1.pop();
	}

	while (!t.empty()) {
		run << t.top() << " ";
		t.pop();
	}
	run << "\n\n+ numbers: \n";

	while (!w.empty()) {
		run << w.top() << " ";
		w.pop();
	}
	run << "\n\nsumma of + numbers: " << sum << "\n";
	run.close();
	return 0;
}