#include <bits/stdc++.h>
using namespace std;

string num;
queue<string> q;
set<string> s;
bool flag;
int pos[4] = {-1, 1, -3 ,3};
int ans;

void bfs() {
	q.push(num);
	s.insert(num);
	
	int idx; 
	while(!q.empty()) {
		int size = q.size();
		for (int i=0; i<size; i++) {
			if(q.front() == "123456780") {
				flag = true;
				return;
			}
			
			for (int j=0; j<9; j++) {
				if(q.front()[j] == '0') {
					idx = j;
					break;
				}
			}
			
			for (int j=0; j<4; j++) {
				int x = idx + pos[j];
				
				if(x < 0 || (idx % 3 == 0 && j == 0) || (idx % 3 == 2 && j == 1) || x >= 9)
					continue;
					
				string copy_num = q.front();
				swap(copy_num[x], copy_num[idx]);
				if(s.count(copy_num) == 0) {
					s.insert(copy_num);
					q.push(copy_num);
				}
			}
			q.pop();
		}
		ans++;
	}
}




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for (int i=0; i<9; i++) {
		char c;
		cin >> c;
		num += c;
	}
	bfs();
	if(flag) cout << ans;
	else cout << -1;
}
