#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	multiset<long long> set;
	int testcase,n;
	cin >> testcase;
	for (int t=0; t<testcase; t++) {
		cin >> n;
		for (int i=0; i<n; i++) {
			char cmd;
			long long num;
			cin >> cmd >> num;
			if(cmd == 'I') {
				set.insert(num);
			}
			else if(cmd == 'D') {
				multiset<long long>::iterator it;
				if(num == -1 && !set.empty()) {
					set.erase(set.begin());
				}
				else if(num == 1 && !set.empty()) {
					it = set.end();
					it--;
					set.erase(it);
				}
			}
		}
		if(set.empty()) {
			cout << "EMPTY" << '\n';
		}
		else {
			multiset<long long>::iterator start, end;
			start = set.begin();
			end = set.end();
			end--;
			cout << *(end) << ' ' << *(start) << '\n';
		}
	}
}
