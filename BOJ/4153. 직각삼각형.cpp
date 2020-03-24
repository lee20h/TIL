#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	bool flag = false;
	while(1) {
		cin >> a >> b >> c;
		if (a==0 && b==0 && c==0)
			break;
		if(a*a + b*b == c*c) flag = true;
		else if(b*b + c*c == a*a) flag = true;
		else if(c*c + a*a == b*b) flag = true;
		else flag = false;
		if(flag) cout << "right" << '\n';
		else cout << "wrong" << '\n';
	}
}
