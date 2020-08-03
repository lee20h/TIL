#include <iostream>
#include <vector>
using namespace std;

vector<int> edge[2001];
int n, m;
bool visited[2001];
bool flag=false;
void search(int start, int count) {
	if(flag) return;
	if(count>=5){
		flag = true;
		return;
	}
	visited[start] = true;
	for (int i=0; i<edge[start].size(); i++) {
		if(!visited[edge[start][i]]) {
			search(edge[start][i],count+1);
		}
	}
	visited[start] = false;
}

int main() {
	
	cin >> n >> m;

	int a,b;
	for (int i=0; i<m; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	
	for (int i=0; i<n; i++) {
		if(flag)
			break;
		search(i,1);
	}
	if(flag) cout << "1";
	else cout << "0";
	return 0;
}
