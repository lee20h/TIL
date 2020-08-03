#include <iostream>
using namespace std;

int v[100][100];

int main() {
	for (int t=1; t<=10; t++) {
		int temp;
		cin >> temp;
		for (int i=0; i<temp; i++) {
			for (int j=0; j<temp; j++) {
				cin >> v[i][j];
			}
		}
		
		int ans = 0;
		for (int j=0; j<temp; j++) {
			int chk = 0;
			for (int i=0; i<temp; i++) {
				if(v[i][j] == 0) continue;
				else if(chk == 0 && v[i][j] == 2) continue;
				else if(chk == 0 && v[i][j] == 1) chk = 1;
				else if(chk == 1 && v[i][j] == 2) {
					chk = 0;
					ans++;
				}
			}
		}
		cout << "#" << t << ' ' << ans << '\n';
	}
}
