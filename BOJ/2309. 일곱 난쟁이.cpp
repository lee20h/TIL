#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v(9);
	int sum = 0;
	for (int i=0; i<9; i++) {
		cin >> v[i];
		sum += v[i];
	}
	sort(v.begin(),v.end());
	int idx, idx2;
	bool flag = false;
	for (int i=0; i<9; i++) {
		sum -= v[i];
		for (int j=0; j<9; j++) {
			if(i == j) continue;
			sum -= v[j];
			if(sum == 100) {
				idx = i;
				idx2 = j;
				flag = true;
				break;
			}
			sum += v[j];
		}
		if(flag) break;
		sum += v[i];
	}
	
	for (int i=0; i<9; i++) {
		if(i == idx || i == idx2) continue;
		cout << v[i] << '\n';
	}
}
