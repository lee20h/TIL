#include <bits/stdc++.h>
using namespace std;

bool visited[100001];
int path[100001];
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	int ans;
	queue<pair<int,int>> q;
	
	cin >> n >> k;
	
	q.push({n,0});
	visited[n] = true;
	
	while(!q.empty()) {
		int dist = q.front().first;
		int sec = q.front().second;
		q.pop();
		
		if(dist == k) {
			cout << sec << '\n';
			int prev = dist;
			v.push_back(prev);
			while(prev != n){
				prev = path[prev];
				v.push_back(prev);
			}
			break;
		}
		
		
		if(dist <= 99999 && !visited[dist+1]) {
			q.push({dist+1,sec+1});
			visited[dist+1] = true;
			path[dist+1] = dist;
		}
		if(dist >= 1 && !visited[dist-1]) {
			q.push({dist-1,sec+1});
			visited[dist-1] = true;
			path[dist-1] = dist;
		}
		if(dist <= 50000 && !visited[dist*2]) {
			q.push({dist*2,sec+1});
			visited[dist*2] = true;
			path[dist*2] = dist;
		}
	}
	
	reverse(v.begin(),v.end());
	for (int i=0; i<v.size(); i++)
		cout << v[i] << ' ';
}
