#include <iostream>
using namespace std;

int main() {
	int n, t, c, p;
	int day = 1;
	int ans = 0;
	cin >> n >> t >> c >> p;
	while(day<n) {
		day += t;
		ans += c*p;
		if (day>n) ans = ans - c*p;
	}
	cout << ans;
}
