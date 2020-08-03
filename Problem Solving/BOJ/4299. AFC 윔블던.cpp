#include <iostream>
using namespace std;

int main() {
	int sum, dif;
	cin >> sum >> dif;
	int a, b;
	a = (sum+dif)/2;
	b = (sum-dif)/2;
	if((sum+dif)%2!=0 || (sum-dif)%2!=0) cout << -1 << '\n';
	else {
		if(a>=0 && b>=0) {
			if(a>b) cout << a << ' ' << b << '\n';
			else cout << b << ' ' << a << '\n';
		}
		else cout << -1 << '\n';
	}
}
