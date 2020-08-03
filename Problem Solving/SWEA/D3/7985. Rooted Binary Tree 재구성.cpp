#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int testcase;
	cin >> testcase;
	for (int t=1; t<=testcase; t++) {
		int depth;
		cin >> depth;
		
		int node = pow(2,depth) - 1;
		vector<int> v;
		for (int i=0; i<node; i++) {
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		
		for (int i=0; i<depth; i++) { //±íÀÌ 
			if(i==0) cout << "#" << t << ' ';
			for (int j=0; j<pow(2,i); j++) { //±íÀÌ Áß ³ëµå ¼ö 
				int temp = (node -1) / pow(2, i+1) + (j * pow(2, depth - i));
				cout << v[temp] << ' ';
			}
			cout << '\n';
		}
	}
}
