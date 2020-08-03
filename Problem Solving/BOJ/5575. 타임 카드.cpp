#include <iostream>
using namespace std;

int main() {
	int h[3], m[3], s[3];
	int a, b, c;
	for (int i=0; i<3; i++) {
		cin >> h[i] >> m[i] >> s[i];
		cin >> a >> b >> c;
		h[i] = a - h[i];
		m[i] = b - m[i];
		s[i] = c - s[i];
		if(s[i]<0) {
			s[i] = s[i] + 60;
			m[i]--;
		}
		if(m[i]<0) {
			m[i] = m[i] + 60;
			h[i]--;
		}
	}
	for (int i=0; i<3; i++) {
		cout << h[i] << ' ' << m[i] << ' ' << s[i] << '\n';
	}
}
