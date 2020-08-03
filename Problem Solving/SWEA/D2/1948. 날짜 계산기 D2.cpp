#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	int m1, m2;
	int d1, d2;
	int day;
	for (int test = 1; test<=t; test++) {
		cin >> m1 >> d1;
		cin >> m2 >> d2;
		day = 1;
		for (int i=m1+1; i<m2; i++) {
			if (i<=7 && i%2!=0) {
				day += 31;
			}
			else if (i<=7 && i%2==0 && i!=2) {
				day += 30;
			}
			else if (i>7 && i%2==0) {
				day += 31;
			}
			else if (i>7 && i%2!=0) {
				day += 30;
			}
			else {
				day += 28;
			}
		}
		if(m1==m2) {
			day += d2-d1;
		}
		else {
			if (m1<=7 && m1%2!=0) {
				day += 31-d1;
			}
			else if (m1<=7 && m1%2==0 && m1!=2) {
				day += 30-d1;
			}
			else if (m1>7 && m1%2==0) {
				day += 31-d1;
			}
			else if (m1>7 && m1%2!=0) {
				day += 30-d1;
			}
			else {
				day += 28-d1;
			}
			day += d2; 
		}
		
		cout << "#" << test << ' ' << day << '\n';
	}
	
}
