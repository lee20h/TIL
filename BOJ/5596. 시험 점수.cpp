#include <iostream>
using namespace std;

int main() {
	int a, b;
	int asum = 0, bsum = 0;
	for (int i=0; i<4; i++) {
		cin >> a;
		asum += a;
	}
	for (int i=0; i<4; i++) {
		cin >> b;
		bsum += b;
	}
	
	asum>bsum ? cout << asum : cout << bsum;
}
