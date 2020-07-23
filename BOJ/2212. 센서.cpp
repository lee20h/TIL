#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> dist;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	int ans = 0;
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(),v.end());
	
	for (int i=0; i<n-1; i++) {
		dist.push_back(abs(v[i] - v[i+1]));
	}
	sort(dist.begin(),dist.end());
	for (int i=0; i<n-k; i++) {
		ans += dist[i];
	}
	cout << ans;
}
