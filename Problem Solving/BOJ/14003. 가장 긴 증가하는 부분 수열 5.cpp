#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> lis;
vector<pair<int,int>> p;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, input;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> input;
		v.push_back(input);
	}
	
	lis.push_back(v[0]);
	p.push_back({0, v[0]});
	
	for (int i=1; i<n; i++) {
		int idx = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
		if(idx >= lis.size())  {
			lis.push_back(v[i]);
		}
		else {
			lis[idx] = v[i];
		}
		p.push_back({idx, v[i]});
	}
	stack<int> st;
	int len = lis.size();
	cout << len << '\n';
	for (int i=n-1; i>=0; i--) {
		if (p[i].first == len-1) {
			st.push(p[i].second);
			len--;
		}
	}
	while(!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}
}
