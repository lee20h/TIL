#include <iostream>
#include <algorithm>
using namespace std;

int ans = 100000000;

void sol(int x, int count, bool flag) {
	if (x==1) {
		flag = true;
		ans = min(count,ans);
	}
	if (ans<=count) return;
	if(x%3==0 && !flag)
		sol(x/3, count+1, flag);
	if(x%2==0 && !flag)
		sol(x/2, count+1, flag);
	if(!flag)
		sol(x-1, count+1, flag);
}

int main() {
	int x;
	cin >> x;
	sol(x,0,false);
	cout << ans;
}
