#include <iostream>
using namespace std;

int main() {
	int num;
	int mul=1;
	cin >> num;
	cout << 1 << ' ';
	for (int i=1; i<=num; i++) {
		mul*=2;
		cout << mul  << ' ';
	}
	return 0;
}
