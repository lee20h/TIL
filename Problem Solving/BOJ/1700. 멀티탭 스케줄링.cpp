#include <bits/stdc++.h>
using namespace std;

int hole[101];
int elec[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	int answer = 0;
	cin >> n >> k;
	for (int i=1; i<=k; i++) {
		cin >> elec[i];
	}
	
	for (int i=1; i<=k; i++) {
		for (int j=1; j<=n; j++) {
			if(hole[j] == 0) { // 구멍 빈 경우 
				hole[j] = elec[i];
				break;
			}
			else { // 구멍 쓰고 있는 경우 
				if(hole[j] == elec[i]) { // 이미 해당 기기가 꽂혀있음 
					break;
				} 
				if(j != n) continue; // 마지막 구멍까지 감
				int swap, val = -1;
				for (int q=1; q<=n; q++) { // 구멍 1~n까지 꽂혀있는 기기 언제 등장하는지 체크 
					int cnt = 0;
					for (int w=i+1; w<=k; w++) {
						if(elec[w] == hole[q]) break;
						cnt++;
					}
					if(cnt > val) { // 후 swap 
						val = cnt;
						swap = q;
					}
				}
				hole[swap] = elec[i];
				answer++;
			}
		}
	}
	cout << answer;
}
