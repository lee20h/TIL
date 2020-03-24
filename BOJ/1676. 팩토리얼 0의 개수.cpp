#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int five = 0;
	for (int i=5; i<=n; i*=5) {
		five += n/i;
	}
	cout << five;
}
