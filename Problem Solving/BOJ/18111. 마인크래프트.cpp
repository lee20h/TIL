#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m, b;
	int ans = 200000000;
	vector<int> v[500];
	int temp;
	int ans2 = 0;
	int high = 0;
	cin >> n >> m >> b;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> temp;
			v[i].push_back(temp);
			high = max(high,temp);
		}
	}
	for(int num = 0; num <= high; num++) {
		temp = b;
		int sec = 0;
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				int height = v[i][j] - num;
				if(height > 0) {
					sec += height * 2;
					temp += height;
				}
				else if(height < 0) {
					sec -= height;
					temp += height;
				}
			}
		}
		if(temp >= 0) {
			if(ans >= sec) {
				ans = sec;
				ans2 = num;
			}
		}
	}
	cout << ans << ' ' << ans2;
}
