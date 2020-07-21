#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<pair<int,int>> v;
	priority_queue<int,vector<int>,greater<int>> q;
	int n;
	cin >> n;
	int s, t;
	for (int i=0; i<n; i++) {
		cin >> s >> t;
		v.push_back({s,t});
	}
	sort(v.begin(),v.end());
	q.push(v[0].second);
	
	for (int i=1; i<n; i++) {
		if(q.top() <= v[i].first) {
			q.pop();
			q.push(v[i].second);
		}
		else {
			q.push(v[i].second);
		}
	}
	cout << q.size();
}
