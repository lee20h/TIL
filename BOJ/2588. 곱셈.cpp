#include <iostream>
using namespace std;

int main() {
	string str1, str2;
	int a[3], b[3];
	cin >> str1 >> str2;
	for (int i=0; i<str1.size(); i++) {
		a[i] = str1[i] - '0';
		b[i] = str2[i] - '0';
	}
	int c = a[2] * b[2] + a[1] * b[2] * 10 + a[0] * b[2] * 100;
	int d = a[2] * b[1] + a[1] * b[1] * 10 + a[0] * b[1] * 100;
	int e = a[2] * b[0] + a[1] * b[0] * 10 + a[0] * b[0] * 100;
	int f = atoi(str1.c_str()) * atoi(str2.c_str());
	cout << c << '\n' << d << '\n' << e << '\n' << f;
}
