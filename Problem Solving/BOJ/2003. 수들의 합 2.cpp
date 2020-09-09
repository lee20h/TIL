#include <bits/stdc++.h>
using namespace std;

const int MAX = 10000+1;

int arr[MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> arr[i];
	
	int ans = 0, sum = 0;
	int left = 0, right = 0;
	
	while(1) {
		if(sum >= m)
			sum -= arr[left++];
		else if(right == n)
			break;
		else
			sum += arr[right++];
		if(sum == m)
			ans++;
	}
	cout << ans;
}
