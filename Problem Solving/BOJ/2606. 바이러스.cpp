#include <iostream> 
#include <vector>
using namespace std;

vector<int> v[101];
bool visited[101];
int cnt;
void dfs(int start) {
	
	for (int i=0; i<v[start].size(); i++) {
		if(visited[v[start][i]] == false) {
			visited[v[start][i]] = true;
			cnt++;
			dfs(v[start][i]);
		}
		
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, com;
	cin >> com;
	cin >> n;
	int a,b;
	for (int i=0; i<n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	visited[1] = true;
	dfs(1);
	cout << cnt;
}
