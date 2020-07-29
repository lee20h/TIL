#include <bits/stdc++.h>
using namespace std;

const int MAX = 50 + 1;
int n, k, ans;
string s[MAX];
char temp[5] = {'a','c','i','n','t'};
bool visited[26];

void sol(int alpha, int cnt) {
	if(cnt == k) {
		int temp = 0;
		for (int i=0; i<n; i++) {
			bool flag = true;
			for (int j=0; j<s[i].length(); j++) {
				if(!visited[s[i][j] - 'a']) {
					flag = false;
					break;
				}
			}
			if(flag) temp++;
		}
		ans = max(ans, temp);
		return;
	}
	
	for (int c = alpha; c<26; c++) {
		if(!visited[c]) {
			visited[c] = true;
			sol(c, cnt+1);
			visited[c] = false;
		}
	}
}

int main() {
	cin >> n >> k;
	if(k < 5){
		cout << 0;
		return 0;
	}
	else if (k == 26) {
		cout << n;
		return 0;
	}
	k -= 5;
	
	for (int i=0; i<n; i++) {
		cin >> s[i];
		s[i] = s[i].substr(4);
		for (int j=0; j<4; j++)
			s[i].pop_back();
	}
	for (int i=0; i<5; i++) {
		visited[temp[i] - 'a'] = true;
	}
	sol(0,0);
	cout << ans;
} 
