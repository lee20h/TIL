#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
void sol(int n, int ans) {
	int mid;
	int right = n-1;
	int left = 0;
	while(right - left >= 0) {
		mid = (right + left) / 2;
		if(ans==v[mid]) {
			cout << "1" << '\n';
			return;
		}
		else if(ans<v[mid]) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << "0" << '\n';
	return;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n;
	int temp;
	for (int i=0; i<n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	cin >> m;
	sort(v.begin(),v.end());
	for (int i=0; i<m; i++) {
		cin >> temp;
		sol(n,temp);
	}
}
