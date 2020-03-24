#include <iostream>
using namespace std;

int main() {
	int l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;
	int day = 1;
	while(c*day< a || d*day< b) {
		day++;
	}
	cout << l - day;
}
