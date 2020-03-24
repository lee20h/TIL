#include <iostream>
#include <vector>
using namespace std;



int w = 0;
int b = 0;
vector<int> v[129];

void div(int cs, int rs, int ce, int re) {
	
	int cur = v[cs][rs];
	
	for (int i=cs; i<ce; i++) {
		for (int j=rs; j<re; j++) {
			if(cur == 0 && v[i][j] == 1)
				cur = -1;
			else if(cur == 1 && v[i][j] == 0)
				cur = -1;
			if(cur == -1) {
				div(cs,rs,(cs+ce)/2,(rs+re)/2);
				div((cs+ce)/2,(rs+re)/2,ce,re);
				div(cs,(rs+re)/2,(cs+ce)/2,re);
				div((cs+ce)/2,rs,ce,(rs+re)/2);
				return;
			}
		}
	}
	if(cur == 0) w++;
	else if (cur == 1) b++;
	return;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	
	int temp;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> temp;
			v[i].push_back(temp);
		}
	}
	div(0,0,n,n); 
	cout << w << '\n' << b;
}
