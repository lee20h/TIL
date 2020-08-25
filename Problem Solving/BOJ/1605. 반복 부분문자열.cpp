#include <bits/stdc++.h>
using namespace std;

const int MOD = 100007;
const int LEN = 200001;

int mod(long long n) {
	if(n >= 0)
		return n % MOD; // 양수
	return ((-n/MOD+1)*MOD + n) % MOD; // 음수 
}

/*
	3033. 가장 긴 문자열과 같은 문제 
*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	string str;
	cin >> n >> str;
	
	int left = 0, right = n;
	while(left+1 < right) {
		int mid = (left + right)/2;
		
		// 해시값이 i 인부분 문자열의 등장 위치 
		vector<vector<int>> position = vector<vector<int>>(MOD, vector<int>());
		int hash = 0, power = 1;
		bool found = false;
		
		// 가능한 모든 위치에서 길이 mid인 부분 문자열들의 해시값을 구해보며 처리 
		for (int i=0; i<=n-mid; i++) {
			if(i==0) {
				for (int j=0; j<mid; j++) {
					hash = mod(hash + 1LL*str[mid-1-j]*power);
					if(j < mid-1)
						power = mod(power*2);
				}
			}
			else
				hash = mod(2*(hash - 1LL*str[i-1]*power) + str[i+mid-1]);
			// 해시값 충 돌 
			if(!position[hash].empty()) {
				// 같은 문자열 등장했는지 비교 
				for (auto p : position[hash]) {
					bool same = true;
					for (int j=0; j<mid; j++) {
						if(str[i+j] != str[p+j]) {
							same = false;
							break;
						}
					}
					if(same) { // 등장 
						found = true;
						break;
					}
				}
			}
			if(found)
				break;
			else
				position[hash].push_back(i); // 못 찾으니 루프 
		}
		
		if(found)
			left = mid;
		else
			right = mid;
	}
	cout << left;
}
