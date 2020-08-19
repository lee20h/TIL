#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6+1;

bool visited[MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int f, s, g, u , d;
	cin >> f >> s >> g >> u >> d; // 識 f類 ⑷營 s類 g類戲煎 檜翕
	
	queue<pair<int,int>> q;
	q.push({s,0});
	int ans = -1;
	while(!q.empty()) {
		int pos = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if(visited[pos])
			continue;
		visited[pos] = true;
		if(pos == g) {
			ans = cnt;
			break;
		}
			
		if(pos < 1 || pos > f)
			continue;
		q.push({pos + u, cnt + 1});
		q.push({pos - d, cnt + 1});
	}
	if(ans == -1) 
		cout << "use the stairs";
	else
		cout << ans;
}
