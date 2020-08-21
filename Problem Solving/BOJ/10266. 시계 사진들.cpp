#include <bits/stdc++.h>
using namespace std;

const int MAX = 360000;

int fail[MAX+100];

bool origin[MAX+100];
bool comp[MAX*2+100];

/*
	바늘이 360000개 만큼 가능하므로 그 들어오는 숫자만큼 bool형 배열로 체크한 뒤,
	그 배열을 두배로 늘려서 들어오는 배열과 KMP 알고리즘으로 비교하였다.
	이 때 MAX값만큼 for문을 돌려야하는게 가장 헷갈렸다. 
*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a;
	cin >> n;
	bool flag = false;
	for (int i=0; i<n; i++) {
		cin >> a;
		comp[a] = comp[a+MAX] = true;
	}
	
	for (int i=0; i<n; i++) {
		cin >> a;
		origin[a] = true;
	}
	
		
	for (int i=1, j=0; i<MAX; i++) {
		while(j>0 && origin[i] != origin[j])
			j = fail[j-1];
		if(origin[i] == origin[j])
			fail[i] = ++j;
	}
	
	for (int i=0, j=0; i<MAX*2; i++) {
		while(j>0 && comp[i] != origin[j])
			j = fail[j-1];
		if(comp[i] == origin[j]) {
			if(j == MAX-1) {
				flag = true;
				break;
			}
			else
				j++;
		}
	}
	if(flag)
		cout << "possible";
	else
		cout << "impossible";
}
