#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare (pair<string, int> &a, pair<string, int> &b) {
	if(a.second==b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main() {
	vector<pair<string, int>> p;
	int n;
	string temp;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> temp;
		p.push_back(make_pair(temp, temp.length()));
	}
	sort(p.begin(),p.end(),compare);
	temp.clear();
	for (int i=0; i<p.size(); i++) {
		if(temp==p[i].first) continue;
		cout << p[i].first << '\n';
		temp = p[i].first;
	}
}
