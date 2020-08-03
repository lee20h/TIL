#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string comp[10] = {"ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN"};
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int testcase;
	cin >> testcase;
	for (int t=1; t<=testcase; t++) {
		string a;
		int b;
		cin >> a >> b;
		string str;
		v.clear();
		for (int i=0; i<b; i++) {
			cin >> str;
			for (int q=0; q<=9; q++) {
				if(str == comp[q]) {
					v.push_back(q);
					break;
				}
			}
		}
		sort(v.begin(),v.end());
		cout << "#" << t << '\n';
		for (int i=0; i<v.size(); i++) {
			cout << comp[v[i]] << ' ';
		}
		cout << '\n';
	}
}
