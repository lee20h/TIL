#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int mul = a*b;
	int d[5];
	for (int i=0; i<5;i++) {
		cin >> d[i];
	}
	for (int i=0; i<5;i++) {
		cout << d[i] - mul << ' ';
	}
	
}
