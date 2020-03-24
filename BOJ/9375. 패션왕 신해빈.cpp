#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test;
	cin >> test;
	vector<pair<string,int>> v;
	for (int t=0; t<test; t++) {
		int n;
		cin >> n;
		string cloth;
		v.clear();
		for (int i=0; i<n; i++) {
			cin >> cloth >> cloth;
			bool flag = false;
			for (int j=0; j<v.size(); j++) {
				if(v[j].first == cloth) {
					v[j].second++;
					flag = true;
					break;
				}
			}
			if(!flag)
				v.push_back(make_pair(cloth,1));
		}
		int sum = 1;
		for (int i=0; i<v.size(); i++) {
			sum *= (v[i].second+1);
		}
		cout << sum-1 << '\n';
	}
}
