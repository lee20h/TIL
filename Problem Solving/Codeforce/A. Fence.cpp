#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		long long a, b, c;
		cin >> a >> b >> c;
		cout << 1ll * (a + b + c) - 1 << '\n';
	}
}
