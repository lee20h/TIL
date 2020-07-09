#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long m;
	int n;
	cin >> n;
	stack<pair<long long,int>> st;
	int temp;
	for (int i=1; i<=n; i++) {
		cin >> m;
		while(!st.empty() && st.top().first < m)
			st.pop();
		if(st.empty()) cout << "0 ";
		else cout << st.top().second << ' ';
		st.push(make_pair(m,i));
	}
}
