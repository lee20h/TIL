#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 987654321;
vector<pair<int, int>> house, chick, v;

int sol() {
	int sum = 0;
	for (int i=0; i<house.size(); i++) {
		int temp = 987654321;
		for (int j=0; j<v.size(); j++)
			temp = min(temp, abs(house[i].first - v[j].first) + abs(house[i].second - v[j].second));
		sum += temp;
	}
	return sum;
}

void dfs(int d, int level) {
	if(level == m) {
		int temp = sol();
		if(ans > temp)
            ans = temp;
		return;
	}
	
	for (int i=d; i<chick.size(); i++) {
		v.push_back(chick[i]);
		dfs(i+1, level+1);
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    for (int i=0; i<n; i++)
    	for (int j=0; j<n; j++) {
    		int temp;
    		cin >> temp;
    		if (temp == 1)
    			house.push_back(make_pair(i,j));
    		else if (temp == 2)
    			chick.push_back(make_pair(i,j));
		}
	dfs(0,0);
	cout << ans;
}
