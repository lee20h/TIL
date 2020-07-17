#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, num;
	priority_queue<int> q;

	cin >> n;
	for (int i=0; i<n*n; i++) {
		cin >> num;
		
		if(q.size() < n) q.push(-num);
		else {
			if(-q.top() < num) {
				q.pop();
				q.push(-num);
			}
		}
	}
	cout << -q.top();
}
