#include <bits/stdc++.h>
using namespace std;

int v[7][10];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string number;
	cin >> number;
	
	int set = 0;
	for (int i=0; i<number.length(); i++) {
		bool flag = false;
		if(number[i] == '6' || number[i] == '9') {
			for (int j=0; j<=set; j++) {
				if(v[j][6] == 0) {
					v[j][6] = 1;
					flag = true;
					break;	
				}
				else if(v[j][9] == 0) {
					v[j][9] = 1;
					flag = true;
					break;
				}
			}
			if(!flag) {
				set++;
				v[set][6] = 1;
			}
		}
		else {
			int temp = number[i] - '0';
			for (int j=0; j<=set; j++) {
				if(v[j][temp] == 0) {
					v[j][temp] = 1;
					flag = true;
					break;
				}
			}
			if(!flag) {
				set++;
				v[set][temp] = 1;
			}
		}
	}
	set++;
	cout << set;
}
