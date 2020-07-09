#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	long long ans = 0;
	int h; 
	cin >> n;
	stack<pair<int,int>> st;
	for (int i=0; i<n; i++) {
		cin >> h;
		
		while(!st.empty() && st.top().first < h) {
			ans += st.top().second;
			st.pop();
		}
		
		if(st.empty())
			st.push(make_pair(h, 1));
		else { // 키가 작을때와 같을 때 
			if(st.top().first == h) {
				pair<int,int> p;
				p = st.top();
				ans += st.top().second;
				st.pop();
				if(!st.empty())
					ans++;
				p.second++;
				st.push(p);
			}
			else {
				st.push(make_pair(h,1));
				ans++;
			}
		}
		
	}
	cout << ans;
	
	
}
