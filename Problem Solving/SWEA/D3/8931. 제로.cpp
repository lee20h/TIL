#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int testcase;
	cin >> testcase;
	for (int t=1; t<=testcase; t++) {
		int k;
		stack<int> st;
		cin >> k;
		int n;
		for (int i=0; i<k; i++) {
			cin >> n;
			if(n==0) st.pop();
			else st.push(n);
		}
		int sum = 0;
		while(!st.empty()) {
			sum += st.top();
			st.pop();
		}
		cout << "#" << t << ' ' << sum << '\n';
	}
}
