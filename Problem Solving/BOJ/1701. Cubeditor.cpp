#include <bits/stdc++.h>
using namespace std;

const int MAX = 5000 + 5;

int arr[MAX];
int ans = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin >> str;
	while(!str.empty()) {
		memset(arr,0,sizeof(arr));
		for (int i=1, j=0; i<str.length(); i++) {
			while(j>0 && str[i] != str[j])
				j = arr[j-1];
			if(str[i] == str[j])
				arr[i] = ++j;
		}
		str = str.substr(1, str.length());
		int temp = 0;
		for (int i=0; i<MAX; i++) {
			temp = max(temp,arr[i]);
		}
		ans = max(ans, temp);
	}
	cout << ans;
}
