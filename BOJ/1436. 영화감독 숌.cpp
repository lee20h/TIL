#include <iostream>
using namespace std;




int main() {
	int n;
	int i, temp, cnt;
	bool ans;
	i = 0;
	cnt = 0;
	cin >> n;	
	while(1) {
		temp = i;
		ans = false;
		while(temp) {
			if(temp % 1000 == 666) ans = true;
			temp = temp / 10;
		}
		if(ans) {
			cnt++;
			
			if(cnt==n) break;
		}
		i++;
	}
	cout << i;
}

