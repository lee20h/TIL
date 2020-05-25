#include <bits/stdc++.h>
using namespace std;

vector<char> v[8];
int ans, len;

void sol(int n, int m) {
	string temp;
	for (int i=n; i<n+len; i++) {
		temp += v[i][m];
	}
	string temp2 = temp;
	reverse(temp.begin(),temp.end());
	if(temp == temp2)
		ans++;
}

void sol2(int n, int m) {
	string temp;
	for (int i=m; i<m+len; i++) {
		temp += v[n][i];
	}
	string temp2 = temp;
	reverse(temp.begin(),temp.end());
	if(temp == temp2)
		ans++;
}

int main() {
	for (int t=1; t<=10; t++) {
		cin >> len;
		ans = 0;
		for (int i=0; i<8; i++)
			v[i].clear();
		for (int i=0; i<8; i++) {
			for (int j=0; j<8; j++) {
				char temp;
				cin >> temp;
				v[i].push_back(temp);
			}
		}
		for (int i=0; i<=8-len; i++) {
			for (int j=0; j<8; j++) {
				sol(i,j);
			}
		}
		for (int i=0; i<8; i++) {
			for (int j=0; j<=8-len; j++) {
				sol2(i,j);
			}
		}
		cout << "#" << t << ' ' << ans << '\n';
	}
}
