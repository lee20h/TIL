#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	int n;
	int a, b, c, d, e, f, g, h;
	for (int test=1; test<=t; test++) {
		cin >> n;
		a=b=c=d=e=f=g=h=0;
		while(n>0) {
			if (n>=50000) {
				a++;
				n-=50000;
			}
			else if (n>=10000) {
				b++;
				n-=10000;
			}
			else if (n>=5000) {
				c++;
				n-=5000;
			}
			else if (n>=1000) {
				d++;
				n-=1000;
			}
			else if (n>=500) {
				e++;
				n-=500;
			}
			else if (n>=100) {
				f++;
				n-=100;
			}
			else if (n>=50) {
				g++;
				n-=50;
			}
			else if (n>=10) {
				h++;
				n-=10;
			}
			else
				n--;
		}
		cout << "#" << test << '\n';
		cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << ' ' << g << ' ' << h << '\n';
	}
	return 0;
}
