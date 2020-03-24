#include<bits/stdc++.h>
using namespace std;
#define max 100000


queue<int> q;
int n, m;
bool visited[100001];

int bfs() {
	int temp = -1;
	int cnt = 0;
	while(1) {
		
		int size = q.size();
		
		for (int i=0; i<size; i++) {
			temp = q.front();
			if(temp == m) {
				return cnt;
			}
			q.pop();
			if(temp+1 <= max && !visited[temp+1]) {
				q.push(temp+1);
				visited[temp+1] = true;
			}
			if(temp*2 <= max && !visited[temp*2]) {
				q.push(temp*2);
				visited[temp*2] = true;
			}
			if(temp-1 >= 0 && !visited[temp-1]) {
				q.push(temp-1);
				visited[temp-1] = true;
			}
		}
		cnt++;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	
	q.push(n);
	
	
	cout << bfs();
}
