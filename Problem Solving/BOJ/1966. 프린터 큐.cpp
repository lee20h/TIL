#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	int test;
	cin >> test;
	for (int i=0; i<test; i++) {
		cin >> n >> m;
		int temp;
		queue<pair<int,int>> q;
		priority_queue<int> pq;
		for (int j=0; j<n; j++) {
			cin >> temp;
			q.push(make_pair(j,temp));
			pq.push(temp);
		}
		int idx, val;
		int cnt = 0;
		while(!q.empty()) {
			idx = q.front().first;
			val = q.front().second;
			q.pop();
			if(pq.top() == val) {
				pq.pop();
				cnt++;
				if(idx == m) {
					cout << cnt << '\n';
					break;
				}
			}
			else q.push(make_pair(idx,val));
		}
	}
}
