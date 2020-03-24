#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;


bool compare (pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

int main() {
	int n;
	cin >> n;
	int age;
	string s;
	vector<pair<int, string>> v;
	for (int i=0; i<n; i++) {
		cin >> age >> s;
		v.push_back(make_pair(age,s));
	}
	stable_sort(v.begin(), v.end(), compare);
	for (int i=0; i<n; i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
}
