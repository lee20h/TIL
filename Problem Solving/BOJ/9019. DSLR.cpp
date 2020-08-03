#include <bits/stdc++.h>
#include <cstring>
using namespace std;

bool visited[10000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	queue<pair<int,string>> q;
	cin >> t;
	int A, B;
	for (int test=0; test<t; test++) {
		cin >> A >> B;
		memset(visited,false,sizeof(visited));
		while(!q.empty())
			q.pop();
		visited[A] = true;
		q.push(make_pair(A,""));
		while(!q.empty()) {
			int number = q.front().first;
			string cmd = q.front().second;
			q.pop();
			
			int temp;
			string temp_cmd;
			temp = (number*2) % 10000;
			if(!visited[temp]) {
				visited[temp] = true;
				temp_cmd = cmd + 'D';
				q.push(make_pair(temp,temp_cmd));
			}
			
			temp = (number-1) < 0 ? 9999 : number-1;
			if(!visited[temp]) {
				visited[temp] = true;
				temp_cmd = cmd + 'S';
				q.push(make_pair(temp,temp_cmd));
			}
			
			temp = ((number % 1000) * 10) + (number / 1000);
			if(!visited[temp]) {
				visited[temp] = true;
				temp_cmd = cmd + 'L';
				q.push(make_pair(temp,temp_cmd));
			}
			
			temp = ((number % 10) * 1000) + (number / 10);
			if(!visited[temp]) {
				visited[temp] = true;
				temp_cmd = cmd + 'R';
				q.push(make_pair(temp,temp_cmd));
			}
			
			if(number == B) {
				cout << cmd << '\n';
				break;
			}
		}
	}
}
