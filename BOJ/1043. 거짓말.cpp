#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> temp[51];
bool visited[51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, q;
	int ans = 0;
	cin >> n >> m;
	cin >> q;
	for (int i=0; i<q; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	for (int i=0; i<m; i++) {
		int per, num;
		cin >> per;
		for (int j=0; j<per; j++) {
			cin >> num;
			temp[i].push_back(num);
		}
	}
	bool check = true;
	while(check) {
		check = false;
		for (int i=0; i<m; i++) {
			bool flag = false;
			if(visited[i]) continue;
			for (int j=0; j<temp[i].size(); j++) {
				if(find(v.begin(),v.end(),temp[i][j]) != v.end()) {
					flag = true;
					check = true;
					break;
				}
			}
			if(flag) {
				v.insert(v.end(),temp[i].begin(),temp[i].end());
				visited[i] = true;
			}
		}
	}
	for (int i=0; i<m; i++) {
		if(!visited[i]) ans++;
	}
	cout << ans;
}
