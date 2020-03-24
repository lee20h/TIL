#include <iostream>
using namespace std;

int main() {
	int m, s=0;
	int x;
	for (int i=0; i<4; i++) {
		cin >> x;
		s += x;
	}
	m = s/60;
	s = s%60;
	cout << m << '\n' << s;
	
}
