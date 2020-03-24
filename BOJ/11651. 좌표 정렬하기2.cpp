#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
	if(a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

int main() {
	int testcase;
	cin >> testcase;
	vector<pair<int, int>> v;
	int x, y;
	for (int i=0; i<testcase; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x,y));
	}
	sort(v.begin(),v.end(),compare);
	for (int i=0; i<testcase; i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
}
