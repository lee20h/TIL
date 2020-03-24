#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int cnt = 0;
	int temp;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> temp;
		bool flag = false;
		if(temp==1) {
			continue;
		}
		for (int i=2; i<temp; i++) {
			if(temp%i==0) {
				flag = true;
				break;
			}
		}
		if(!flag) cnt++;
	}
	cout << cnt;
}
