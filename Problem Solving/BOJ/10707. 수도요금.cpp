#include <iostream>
using namespace std;

int main() {
	int a, b, c, d, p;
	int x, y;
	cin >> a >> b >> c >> d >> p;
	x = a*p;
	if(c>=p) y = b;
	else {
		y = b + ((p-c) * d);
	}
	x<y ? cout << x : cout << y;
}
