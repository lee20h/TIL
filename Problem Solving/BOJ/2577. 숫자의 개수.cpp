#include <iostream>
#include <string>
using namespace std;


int ans[10];

int main() {
	int a, b, c;
	int mul;
	cin >> a >> b >> c;
	mul = a*b*c;
	while(mul>0) {
		ans[mul%10] += 1;
		mul /= 10;
	}
	for (int i=0; i<10; i++) {
		cout << ans[i] << '\n';
	}
}
