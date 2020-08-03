#include <iostream>
using namespace std;

int main() {
	int h, m, s;
	int cook;
	cin >> h >> m >> s;
	cin >> cook;
	s = cook + s;
	m = m + (s/60);
	s = s % 60;
	h = h + (m/60);
	m = m % 60;
	while(h>=24) h-=24;
	cout << h << ' ' << m << ' ' << s;
}
