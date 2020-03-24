#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int d,w,h;
	cin >> d >> w >> h;
	double a, rw, rh;
	a = sqrt(pow(w,2)+pow(h,2));
	rw = w * d / a;
	rh = h * d / a;
	cout << (int)rw << ' ' <<  (int)rh;
}
