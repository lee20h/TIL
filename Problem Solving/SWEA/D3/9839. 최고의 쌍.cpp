#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int testcase;
	cin >> testcase;
	
	for (int t=1; t<=testcase; t++) {
		int n;
		cin >> n;
		vector<int> v;
		for (int i=0; i<n; i++) {
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		
		int ans = -1;
		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
				int num = v[i] * v[j];
				bool flag = true;
				
				int digit = num % 10;
				num /= 10;
				while(num) {
					if(digit - 1 == num%10) {
						digit--;
						num /= 10;
					}
					else {
						flag = false;
						break;
					}
				}
				
				if(flag && ans < v[i] * v[j]) ans = v[i] * v[j];
			}
		}
		cout << "#" << t << ' ' << ans << '\n';

	}
}
