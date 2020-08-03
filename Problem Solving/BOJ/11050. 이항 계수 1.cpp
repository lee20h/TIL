#include <iostream>
#include <cstring>
using namespace std;


int main() {
	int n, k;
	cin >> n >> k;
	int a = 1;
	int b = 1;
	for (int i=0; i<k; i++) {
		a *= n-i;
	}
	for (int i=1; i<=k; i++) {
		b *= i;
	}
	
	cout << a/b;
}
