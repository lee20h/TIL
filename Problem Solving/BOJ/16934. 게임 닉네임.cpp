#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5+1;
int idx;
/*
	트라이를 구성한 뒤 트라이에 삽입하면서 별칭을 저장해 출력해준다. 
*/
struct Node {
	int finish;
	int point[26];
}nodes[MAX*3];

Node* newNode() {
	nodes[idx].finish = 0;
	return &nodes[idx++];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	string input;
	cin >> n;
	
	Node* alpha = newNode();
	
	for (int i=0; i<n; i++) {
		cin >> input;
		int len = input.length();
		bool res = false;
		string ans;
		
		Node* cur = alpha;
		
		for (int i=0; i<len; i++) {
			if(!cur->point[input[i] -'a']) {
				Node* node = newNode();
				cur->point[input[i] - 'a'] = idx - 1;
				if(!res) {
					res = true;
					ans = input.substr(0,i+1);
				}
				
			}
			cur = &nodes[cur->point[input[i] - 'a']];
		}
		cur->finish++;
		if(!res) {
			if(cur->finish == 1)
				cout << input << '\n';
			else
				cout << input << cur->finish << '\n';
		}
		else
			cout << ans << '\n';
	}
}
