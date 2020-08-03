#include <bits/stdc++.h>
using namespace std;

char v[51][51];
int n;
int ans;
int cnt = 1;

void row() {
	for (int i=0; i<n; i++) {
		cnt = 1;
		char temp = v[0][i];
		for (int j=1; j<n; j++) {
			if(temp == v[j][i]) {
				cnt++;
			}
			else {
				temp = v[j][i];
				ans = max(ans,cnt);
				cnt = 1;
			}
		}
		ans = max(ans,cnt);
	}
}

void col() {
	for (int i=0; i<n; i++) {
		cnt = 1;
		char temp = v[i][0];
		for (int j=1; j<n; j++) {
			if(temp == v[i][j]) {
				cnt++;
			}
			else {
				temp = v[i][j];
				ans = max(ans,cnt);
				cnt = 1;
			}
		}
		ans = max(ans,cnt);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> v[i][j];
		}
	}
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n-1; j++) {
			swap(v[i][j],v[i][j+1]);
			row();
			col();
			swap(v[i][j],v[i][j+1]);
			
			swap(v[j][i],v[j+1][i]);
			row();
			col();
			swap(v[j][i],v[j+1][i]);
		}
	}
	cout << ans;
} 
