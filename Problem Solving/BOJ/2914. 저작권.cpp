#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	for (int i=0; i<1000000; i++) {
		if(i/a+1==b) {
			cout << i+1;
			break;
		}
	}
}
