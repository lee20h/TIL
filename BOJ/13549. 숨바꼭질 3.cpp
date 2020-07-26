#include <bits/stdc++.h>
using namespace std;

bool visited[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	cin >> n >> k;
	q.push({0,n});
	visited[n] = true;
	while(!q.empty()) {
		int dist = q.top().second;
		int sec = q.top().first;
		if(dist == k) {
			cout << sec;
			return 0;
		}
		q.pop();
		visited[dist] = true;
		
		if(dist <= 50000 && !visited[dist*2])
			q.push({sec,dist*2});
		if(dist >= 1 && !visited[dist-1])
			q.push({sec+1,dist-1});
		if(dist <= 99999 && !visited[dist+1])
			q.push({sec+1,dist+1});
	}
}
