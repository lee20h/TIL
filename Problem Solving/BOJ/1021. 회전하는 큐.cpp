#include <bits/stdc++.h>
using namespace std;

deque<int> dq;
int cnt;

void oper1() {
	dq.push_back(dq.front());
	dq.pop_front();
	cnt++;
}

void oper2() {
	dq.push_front(dq.back());
	dq.pop_back();
	cnt++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		dq.push_back(i);
	}
	
	for (int i=0; i<m; i++) {
		int num;
		cin >> num;
		int idx;
		for (int j=0; j<dq.size(); j++) {
			if(dq[j] == num) {
				idx = j;
				break;
			}
		}
		
		if(dq.front() == num) {
			dq.pop_front();
			continue;
		}
		
		while(1) {
			if(dq.front() == num) {
				dq.pop_front();
				break;
			}
			if(idx > dq.size() - idx)
				oper2();
			else
				oper1();
			}
		}
		
	
	cout << cnt;
}
