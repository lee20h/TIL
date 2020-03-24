#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, m;
	vector<char> v[51];
	cin >> n >> m;
	char temp;
	int ans=64, cnt;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> temp;
			v[i].push_back(temp);
		}
	}
	
	for (int i=0; i <= n-8; i++) {
		for (int j=0; j <= m-8; j++) {
			cnt = 0;
			for (int q=i; q < i+8; q++) {
				for (int w=j; w < j+8; w++) {
					if((q+w) % 2 == 0) {
						if(v[q][w]=='W') cnt++;
					}
					else {
						if(v[q][w]=='B') cnt++;
					}
				}
			}
			cnt = min(cnt, 64-cnt);
			ans = min(ans, cnt);
		}
	}
	cout << ans;
}
