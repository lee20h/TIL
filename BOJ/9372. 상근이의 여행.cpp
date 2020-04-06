#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	int n, m; //n 국가 m 비행기 종류 
	int a, b;
	cin >> t; 
	for (int test=0; test<t; test++) {
		cin >> n >> m;
		
		for (int i=0; i<m; i++){
			cin >> a >> b;
 		}
		
		cout << n-1 << '\n';
	}
}
