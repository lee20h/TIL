#include <iostream>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	int h, w, n;
	for (int i=0; i<testcase; i++) {
		cin >> h >> w >> n;
		string ans;
		int k=1;
		int q=1;
		for (int j=1; j<=n; j++) {
			if(k==h+1) {
				k=1;
				q++;	
			}
			if(j==n) ans += to_string(k);
			k++;
			
		}
		if(q<10) {
			ans += '0';
			ans += to_string(q);
		}
		else ans+= to_string(q);
		cout << ans << '\n';
	}
}
