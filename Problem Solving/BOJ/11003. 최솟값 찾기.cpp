#include <bits/stdc++.h>
using namespace std;

const int MAX = 500000;

int v[MAX];
deque<pair<int,int>> dq;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, l;
	cin >> n >> l;
	for (int i=0; i<n; i++) {
		cin >> v[i];
	}
	//dq vale, idx
	for (int i=0; i<n; i++) {
		if (!dq.empty() && dq.front().second <= i - l)
			dq.pop_front();
		while(!dq.empty() && dq.back().first > v[i])
			dq.pop_back();
		dq.push_back({v[i],i});
		cout << dq.front().first << ' ';
	}
}
