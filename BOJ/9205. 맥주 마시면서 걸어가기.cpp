#include <bits/stdc++.h>
#include <cstring>
using namespace std;

vector<int> v[103];
bool visited[103];

int dist(pair<int,int> v1, pair<int,int> v2) {
	return abs(v1.first - v2.first) + abs(v1.second - v2.second);
}

void dfs(int start) {
	visited[start] = true;
	for (int i=0; i<v[start].size(); i++) {
		int next = v[start][i];
		if(!visited[next]) dfs(next);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	
	for (int testcase=0; testcase<t; testcase++) {
		int n;
		vector<pair<int, int>> pos;
		cin >> n;
		for (int i=0; i<103; i++)
			v[i].clear();
		memset(visited, false, sizeof(visited));
		for (int i=0; i<n+2; i++) {
			int y,x;
			cin >> y >> x;
			pos.push_back(make_pair(y,x));
		}
		
		for (int i=0; i<n+2; i++) {
			for (int j=i+1; j<n+2; j++) {
				if(dist(pos[i], pos[j]) <= 50 * 20) {
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}
		dfs(0);
		if(visited[n+1]) cout << "happy" << '\n';
		else cout << "sad" << '\n';
	}
}
