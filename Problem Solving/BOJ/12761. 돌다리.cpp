#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;
bool visited[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, n, m;
	cin >> a >> b >> n >> m;
	queue<pair<int, int>> q;
	
	q.push(make_pair(n,0));
	int temp, cnt;
	visited[n] = true;
	while(!q.empty()) {
		temp = q.front().first;
		cnt = q.front().second;
		q.pop();
		if(temp == m) {
			break;
		}
		if (temp - 1 >= 0 && !visited[temp-1]) {
			visited[temp-1] = true;
			q.push(make_pair(temp-1,cnt+1));
		}
		if (temp + 1 < MAX && !visited[temp+1]) {
			visited[temp+1] = true;
			q.push(make_pair(temp+1,cnt+1));
		}
		if (temp + a < MAX && !visited[temp+a]) {
			visited[temp+a] = true;
			q.push(make_pair(temp+a,cnt+1));
		}
		if (temp - a >= 0 && !visited[temp-a]) {
			visited[temp-a] = true;
			q.push(make_pair(temp-a,cnt+1));
		}
		if (temp + b < MAX && !visited[temp+b]) {
			visited[temp+b] = true;
			q.push(make_pair(temp+b,cnt+1));
		}
		if (temp - b >= 0 && !visited[temp-b]) {
			visited[temp-b] = true;
			q.push(make_pair(temp-b,cnt+1));
		}
		if (temp * a < MAX && !visited[temp*a]) {
			visited[temp*a] = true;
			q.push(make_pair(temp*a,cnt+1));
		}
		if (temp * b < MAX && !visited[temp*b]) {
			visited[temp*b] = true;
			q.push(make_pair(temp*b,cnt+1));
		}
		
	}
	cout << cnt;
}
