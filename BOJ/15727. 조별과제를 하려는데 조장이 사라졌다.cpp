#include <iostream>
using namespace std;

int main() {
	int dis, ans;
	cin >> dis;
	ans = dis/5;
	if(dis%5!=0) ans++;
	cout << ans;
}
