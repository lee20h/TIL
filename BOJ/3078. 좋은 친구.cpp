#include <bits/stdc++.h>
using namespace std;

queue<int> q[21];
int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	long long ans = 0;
	for (int i=0; i<n; i++) {
		string temp;
		cin >> temp;
		int len = temp.length();
		if(q[len].empty())
			q[len].push(i);
		else {
			while(i - q[len].front() > k) {
				if(q[len].empty()) break;
				q[len].pop();
			}
				
			ans += q[len].size();
			q[len].push(i);
		}
	}
	cout << ans;
}
