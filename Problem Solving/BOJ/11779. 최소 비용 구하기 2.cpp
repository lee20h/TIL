#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 1;
const int INF = 1e9;

vector<pair<int,int>> v[MAX];
bool visited[MAX][MAX];
int n, m;
int Start, End;
int arr[MAX];

int dijkstra(int node) {
	vector<int> dist(n+1, INF);
	dist[node] = 0;
	
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	q.push({0,node});
	while(!q.empty()) {
		int cost = q.top().first;
		int curr = q.top().second;
		q.pop();
		
		if(dist[curr] < cost)
			continue;
			
		for(int i=0; i<v[curr].size(); i++) {
			int neighb = v[curr][i].first;
			int neighc = v[curr][i].second + cost;
			
			if(dist[neighb] > neighc) {
				dist[neighb] = neighc;
				q.push({neighc, neighb});
				arr[neighb] = curr;
			}
		}
	}
	return dist[End];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b,c});
	}
	cin >> Start >> End;
	
	cout << dijkstra(Start) << '\n';
	
	stack<int> st;
	int node = End;
	while(node) {
		st.push(node);
		node = arr[node];
	}
	cout << st.size() << '\n';
	
	while(!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}
}
