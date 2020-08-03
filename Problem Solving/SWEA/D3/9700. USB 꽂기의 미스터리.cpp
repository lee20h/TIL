#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int tc;
	cin >> tc;
	
	for (int t=1; t<=tc; t++) {
		double p, q;
		
		cin >> p >> q;
		double s1, s2;
		double sp, sq;
		sp = 1 - p;
		sq = 1 - q;
		s1 = sp * q;
		s2 = p * sq * q;
		if(s1<s2) 
			cout << "#" << t << ' ' << "YES" << '\n';
		else
			cout << "#" << t << ' ' << "NO" << '\n';
	}
}
