#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cout << fixed;
	cout.precision(6);
	int r;
	double s1, s2;
	cin >> r;
	s1 = r*r*M_PI;
	s2 = r*r*2;
	cout << s1 << '\n';
	cout << s2;
}
