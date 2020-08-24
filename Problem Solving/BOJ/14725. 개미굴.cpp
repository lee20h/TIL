#include <bits/stdc++.h>
using namespace std;

struct Node{
	map<string, Node> child;
}root;

void insert(Node &v, vector<string> &arr, int idx){
	if(idx == arr.size())
		return;
	
	if(!v.child.count(arr[idx]))
		v.child[arr[idx]] = Node();
	insert(v.child[arr[idx]], arr, idx+1);
}

void dfs(Node &v, int dep = 0) {
	for (auto i : v.child) {
		for (int j=0; j<dep; j++) 
			cout << "--";
		cout << i.first << "\n";
		dfs(i.second, dep+1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string a;
		vector<string> v(n);
		for (int i=0; i<n; i++)
			cin >> v[i];
		insert(root, v, 0);
	}
	dfs(root);
	
}
