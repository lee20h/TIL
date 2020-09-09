#include <bits/stdc++.h>
using namespace std;

const int MAX = 15000+1;

int arr[MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	for (int i=0; i<n; i++)
		cin >> arr[i];
	
	sort(arr,arr+n);
	
	int left = 0, right = n-1;
	int ans = 0;
	while(left < right) {
		if(arr[left] + arr[right] == m) {
			ans++;
			left++;
		}
		else if(arr[left] + arr[right] < m)
			left++;
		else
			right--;
	} 
	cout << ans;
}
