#include <iostream>
using namespace std;

int main() {
	int h, m;
	int oven;
	cin >> h >> m >> oven;
	m = m+oven;
	while(m>=60) {
		m -= 60;
		h++;
	}
	if(h>=24)
		h-=24;
	cout << h << ' ' << m;
}
