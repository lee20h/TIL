#include <iostream>
using namespace std;

int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	int count = 1;
	if(b>=c) {
		cout << "-1";
		return 0;
	}
	cout << a/(c-b) + 1;
} 
