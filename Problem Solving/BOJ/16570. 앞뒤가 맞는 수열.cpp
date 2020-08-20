#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6+1;

int arr[MAX];
int sub[MAX];
int fail[MAX];

/*
	앞을 자르고 부분 문자열의 접두사와 접미사의 같은 길이 중 최대를 구하고자 한다.
	이 때 앞을 자르는 것을 거꾸로 생각하면 끝에서부터 kmp로 실패함수 값을 구하는것과 같다. 
*/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i=n-1; i>=0; i--) {
		cin >> arr[i];
	}
	
	for (int i=1, j=0; i<n; i++) {
		while(j>0 && arr[i] != arr[j])
			j = fail[j-1];
		if(arr[i] == arr[j])
			fail[i] = ++j;
	}
	
	int ans = -1, cnt = 1;
	
	for (int i=0; i<n; i++) {
		if(fail[i]) {
			
			if(ans < fail[i]) {
				cnt = 1;
				ans = fail[i];
			}
			else if(ans == fail[i])
				cnt++;
		}
	}
	if(ans == -1)
		cout << ans;
	else
		cout << ans << ' ' << cnt;
	
}
