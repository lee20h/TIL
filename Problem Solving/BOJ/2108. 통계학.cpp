#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool comp2(pair<int,int> &a, pair<int,int> &b) {
	if(a.second==b.second) return a.first < b.first;
	else return a.second > b.second;
}
int main() {
	int n;
	cin >> n;
	vector<int> v;
	int fre;
	double sum = 0;
	vector<pair<int,int>> p;
	vector<int>::size_type i;
	for (int i=0; i<n; i++) {
		cin >> fre;
		v.push_back(fre);
		sum += fre;
	}
	sort(v.begin(),v.end());
	cout << (int)floor((sum/n) + 0.5) << '\n';
	cout << v[n/2] << '\n';
	
	for (int i=0; i<v.size(); i++) {
		if(p.empty()) {
			p.push_back(make_pair(v[i],1));
			continue;
		}
		
		if(p.back().first == v[i]) {
			pair<int,int> temp = p.back();
			temp.second++;
			p.pop_back();
			p.push_back(temp);
		}
		else p.push_back(make_pair(v[i],1));
	}
	
	sort(p.begin(),p.end(), comp2);
	if (p[0].second == p[1].second) cout << p[1].first << '\n';
	else cout << p[0].first << '\n';
	
	cout << v.back()-v.front();
}
