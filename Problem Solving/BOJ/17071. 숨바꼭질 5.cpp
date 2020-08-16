#include <bits/stdc++.h>
using namespace std;

const int MAX = 500000;
bool visited[MAX][2];
int n, k, cnt;

int bfs() {
	queue<pair<int,int>> q;
	q.push({n,cnt});
	visited[n][cnt] = true;
	while(!q.empty()) {
		if(visited[k][cnt&1])
			return cnt;
		
		int now = q.front().first;
		int num = q.front().second;
		q.pop();
		
		if(num > cnt)
			k += ++cnt;
			
		if(k > MAX)
			break;
		
		int oper[3] = {-1,1,now};
		for (int i=0; i<3; i++) {
			int d = oper[i];
			if(now + d < 0 || now + d > MAX)
				continue;
				
			if(visited[now+d][(num+1)&1])
				continue;
				
			q.push({now+d,num+1});
			visited[now+d][(num+1)&1] = true;
		}
	}
	return -1;
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	cout << bfs();
}
