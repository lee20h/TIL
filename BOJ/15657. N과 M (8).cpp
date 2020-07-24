#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n, m;
vector<int> vec;

void sol(int len) {
	if(vec.size() == m) {
		for (int i=0; i<vec.size(); i++) {
			cout << vec[i] << ' ';
		}
		cout << '\n';
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
}
