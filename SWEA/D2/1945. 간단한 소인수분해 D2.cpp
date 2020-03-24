#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	int num;
	int a, b, c, d, e;
	for (int test = 1; test<=t; test++) {
		cin >> num;
		a=b=c=d=e=0;
		
		while(num>1) {
			if (num%2==0) {
				num /= 2;
				a++;
			}
			else if (num%3==0) {
				num /= 3;
				b++;
			}
			else if (num%5==0) {
				num /= 5;
				c++;
			}
			else if (num%7==0) {
				num /= 7;
				d++;
			}
			else {
				num /= 11;
				e++;
			}
		}
		
		cout << "#" << test << ' ' << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';		
	}
	return 0;
}
