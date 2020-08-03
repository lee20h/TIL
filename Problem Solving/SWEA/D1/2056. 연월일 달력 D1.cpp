#include <iostream>
#include <string>
using namespace std;

int main(){
	int t;
	cin >> t;
	int num;
	int m, d;
	string y, temp;
	for (int i=1; i<=t; i++) {
		cin >> temp;
		num = atoi(temp.c_str());
		y = temp.substr(0,4);
		m = num%10000/100;
		d = num%100;
		if(0<m && m<10) {
			if (m==2) {
				if(d>28 || d<1) {
					cout << "#" << i << ' ' << "-1" << '\n';
					continue;	
				}
			}
			else if(m==4&&m==6&&m==9) {
				if(d>30 || d<1) {
					cout << "#" << i << ' ' << "-1" << '\n';
					continue;	
				}
			}
			else {
				if(d>31 || d<1) {
					cout << "#" << i << ' ' << "-1" << '\n';
					continue;	
				}
			}
			if(d>10)
				cout << "#" << i << ' ' <<y << "/" << "0" << m << "/" << d << '\n';
			else
				cout << "#" << i << ' ' <<y << "/" << "0" << m << "/" << "0" << d << '\n';
		}
		else if (9<m && m<13) {
			if (m%2==0) {
				if(d>31 || d<1) {
					cout << "#" << i << ' ' << "-1" << '\n';
					continue;	
				}	
			}
			else {
				if(d>30 || d<1) {
					cout << "#" << i << ' ' << "-1" << '\n';
					continue;	
				}
			}
			if(d>10)
				cout << "#" << i << ' ' <<y << "/" << m << "/" << d << '\n';
			else
				cout << "#" << i << ' ' <<y << "/" << m << "/" << "0" << d << '\n';
		}
		else cout << "#" << i << ' ' << "-1" << '\n';
	}
}
