#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int acnt,bcnt,ccnt;
	acnt = 0;
	bcnt = 0;
	ccnt = 0;
	while(n>=10) {
		if(n%300==0) {
			acnt++;
			n = n - 300;
		}
		else if(n%60==0) {
			bcnt++;
			n = n - 60;
		} 
		else if(n%10==0) {
			ccnt++;
			n = n - 10;
		}
		else break;
	}
	if(n!=0) cout << "-1";
	else
		cout << acnt << ' ' << bcnt << ' ' << ccnt;
	
}
