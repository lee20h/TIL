#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> v;
	int n; 
	cin >> n;
	string cmd;
	int num;
	for (int i=0; i<n; i++) {
		cin >> cmd;
		vector<int>::iterator it;
		if(cmd == "add") {
			cin >> num;
			it = find(v.begin(),v.end(),num);
			if (it == v.end()) v.push_back(num);
		}
		else if (cmd == "remove") {
			cin >> num;
			it = find(v.begin(),v.end(),num);
			if (it != v.end()) v.erase(it);
		}
		else if (cmd == "check") {
			cin >> num;
			it = find(v.begin(),v.end(),num);
			if (it == v.end()) cout << "0" << '\n';
			else cout << "1" << '\n';
		}
		else if (cmd == "toggle") {
			cin >> num;
			it = find(v.begin(),v.end(),num);
			if (it != v.end()) v.erase(it);
			else v.push_back(num);
		}
		else if (cmd == "all") {
			v.clear();
			for (int i=1; i<=20; i++)
				v.push_back(i);
		}
		else if (cmd == "empty") {
			v.clear();
		}
	}
}
