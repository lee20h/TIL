#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e9;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, h, ans = MAX, cnt;
	cin >> n >> h;
	vector<int> top(n/2), bot(n/2);
	for (int i=0; i<n/2; i++) {
		cin >> bot[i] >> top[i];
	}
	sort(top.begin(), top.end());
	sort(bot.begin(), bot.end());
	
	for (int i=1; i<=h; i++) {
		int obstacle = bot.size() - (lower_bound(bot.begin(), bot.end(), i) - bot.begin());
		obstacle += top.size() - (upper_bound(top.begin(), top.end(), h - i) - top.begin());
		if(ans > obstacle) {
			ans = obstacle;
			cnt = 1;
		}
		else if (ans == obstacle)
			cnt++;
	}
	
	cout << ans << ' ' << cnt;
}
