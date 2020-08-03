#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long l, w, h;
	long long n;
	cin >> l >> w >> h;
	cin >> n;
	vector<pair<long long,long long>> v; // 큐브 담는 벡터 
	for (int i=0,x, y; i<n; i++) {
		cin >> x >> y;
		v.push_back({x,y});
	}
	
	sort(v.begin(),v.end()); 
	reverse(v.begin(),v.end()); // 큐브에서 first기준으로 내림차순 
	
	long long check = 0, ans = 0, temp = 0;
	for (int i=0; i<v.size(); i++) { // 가장큰 값부터 8배로 늘려서 min값 구하기 
		check <<= 3; // 면이 3면이므로 2*2*2 = 8배 
		temp = min(v[i].second, ((l >> v[i].first) * (w >> v[i].first) * (h >> v[i].first) - check));
		check += temp;
		ans += temp;
	}
	if(l*w*h == check)
		cout << ans;
	else
		cout << "-1";
} 
