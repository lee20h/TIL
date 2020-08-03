#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	int n, x;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x;
		if (x==0) {
			if(q.empty()) {
				cout << "0" << '\n';
			}
			else {
				pair<int,int> temp = q.top();
				q.pop();
				cout << temp.first * temp.second <<'\n';
			}
		}
		else {
			if(x<0) {
				q.push(make_pair(abs(x),-1));
			}
			else {
				q.push(make_pair(abs(x),1));
			}
		}
	}
	 
	
} 
