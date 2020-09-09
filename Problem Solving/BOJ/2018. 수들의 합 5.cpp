#include <bits/stdc++.h>
using namespace std;

const int MAX = 10000000/2+1;

int arr[MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int ans = 1, sum = 0;
	int left = 1, right = 1;
	
	for (int i=1; i<=n/2+1; i++)
		arr[i] = i;
	
	while(1) {
		if(sum >= n)
			sum -= arr[left++];
		else if (right > n/2+1)
			break;
		else
			sum += arr[right++];
		if(sum == n)
			ans++;
	}
	cout << ans;
}
