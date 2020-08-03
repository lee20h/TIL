#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n, m;
vector<int> vec;
vector<int> temp;
set<vector<int>> s;

void sol(int len) {
	if(vec.size() == m) {
		s.insert(vec);
		return;
	}
	
	for (int i=len; i<v.size(); i++) {
		vec.push_back(v[i]);
		sol(i);
		vec.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	
	
	sort(v.begin(),v.end());
	sol(0);
	
	set<vector<int>>::iterator it;
	for (it =s.begin(); it!=s.end(); it++) {
		for (int i=0; i<it->size(); i++) {
			cout << it->at(i) << ' ';
		}
		cout << '\n';
	}
}
