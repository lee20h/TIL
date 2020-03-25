#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, m, cnt;
int bnt[10] = {1,1,1,1,1,1,1,1,1,1};

void sol(string num) {
	for (int i=0; i<=9; i++) {
		if(bnt[i]) {
			string temp = num + to_string(i);
			int temp_int = abs(n - stoi(temp)) + temp.length();
			cnt = min(cnt,temp_int);
			if(temp.length() < 6)
				sol(temp);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	cnt = abs(n-100);
	for (int i=0; i<m; i++) {
		int temp;
		cin >> temp;
		bnt[temp] = 0;
	}
	string empty = "";
	sol(empty);
	cout << cnt;
}
