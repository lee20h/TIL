#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 1;

int len[MAX];
int sub[MAX];
vector<int> programs[MAX];
int n, k;
bool checked[MAX];
int fail[MAX];
/*
	첫번째 프로그램 코드에서 K개 씩 가능한 모든 경우의 수로 나머지 프로그램에 KMP 적용해서 공통 부분 수열 확인
	J번째 프로그램에서 KMP 적용 후 reverse시켜서 다시 KMP 확인 
*/                             

bool kmp(int idx) {
	memset(fail,0,sizeof(fail));
	for(int i=1, j=0; i<k; i++) {
		while(j > 0 && sub[i] != sub[j]) 
			j = fail[j-1];
		if(sub[i] == sub[j])
			fail[i] = ++j;
	}
	
	for (int i=0, j=0; i<len[idx]; i++) {
		while(j > 0 && programs[idx][i] != sub[j])
			j = fail[j-1];
		if(programs[idx][i] == sub[j]) {
			if(j == k-1) { // k개 씩 가능한 경우의  수 
				return true;
			}
			else
				j++;
		}
	}
	return false;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int p=0; p<n; p++) {
		cin >> len[p];
		vector<int> t(len[p]);
		for (int i=0; i<len[p]; i++) {
			cin >> t[i];
			programs[p] = t;
		}
	}
	bool ans = false;
	for (int i=0; i<=len[0]-k; i++) { // 첫 프로그램에서 K개씩 짜름 
		for (int j=0; j<k; j++)
			sub[j] = programs[0][i+j];
		
		memset(checked, false, sizeof(checked));
		
		for (int j=1; j<n; j++)
			checked[j] = kmp(j);
			
		for (int j=1; j<n; j++) {
			if(checked[j])
				continue;
			
			reverse(programs[j].begin(), programs[j].end());
			checked[j] = kmp(j);
		}
		
		bool flag = true;
		for (int j=1; j<n; j++) {
			if(!checked[j]) {
				flag = false;
				break;
			}
		}
		
		if(flag) {
			ans = true;
			break;
		}
	}
	if(ans)
		cout << "YES";
	else
		cout << "NO";
}
