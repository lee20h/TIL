#include <iostream>
#include <vector>
using namespace std;
vector<int> g(50);
int main() {
	vector<pair<int,int>> v;
	int n;
	cin >> n;
	int h, w;
	for (int i=0; i<n; i++) {
		cin >> h >> w;
		v.push_back(make_pair(h,w));
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if(i==j) continue;
			if(v[i].first < v[j].first && v[i].second < v[j].second) {
					g[i]++;
			}
		}
	}
	for (int i=0; i<n; i++) {
		cout << g[i]+1 << '\n';
	}
}
