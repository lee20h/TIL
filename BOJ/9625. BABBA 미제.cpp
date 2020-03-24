#include <iostream>
using namespace std;

int main() {
	int n;
	int a[45];
	int b[45];
	a[0] = 0;
	b[0] = 1;
	a[1] = 1;
	b[1] = 1;
	cin >> n;
	
	for (int i=2; i<45; i++) {
		a[i] = a[i-2] + a[i-1];
		b[i] = b[i-2] + b[i-1];
	}
	cout << a[n-1] << ' ' << b[n-1];
}
