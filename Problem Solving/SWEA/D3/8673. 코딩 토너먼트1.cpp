#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int testcase;
	cin >> testcase;
	for (int t=1; t<=testcase; t++) {
		int n;
		int ans = 0;
		queue<int> q;
		cin >> n;
		for (int i=0; i<pow(2,n); i++) {
			int temp;
			cin >> temp;
			q.push(temp);
		}
		
		while(!q.empty()) {
			int left = q.front();
			q.pop();
			if(q.empty()) break;
			int right = q.front();
			q.pop();
			
			if(left < right) {
				ans += right - left;
				q.push(right);
			}
			else {
				ans += left - right;
				q.push(left);
			}
		}
		
		cout << "#" << t << ' ' << ans << '\n';
	}
}
