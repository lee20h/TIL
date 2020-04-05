#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> ans;
bool visited[50];
int N;

void dfs(int num) {
	if(ans.size() == 6) {
		for (int i=0; i<6; i++) {
			cout << ans[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i=num; i<N; i++) {
		if(!visited[i]) {
			visited[i] = true;
			ans.push_back(v[i]);
			dfs(i);
			ans.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(1) {
		cin >> N;
		if(N==0) break;
		v.clear();
		ans.clear();
		for(int i=0; i<N; i++)
			visited[i] = false;
		for (int i=0; i<N; i++) {
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		sort(v.begin(),v.end());
		
		dfs(0);
		
		cout << '\n';
	}
}
