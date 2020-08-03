#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> ans;
	int n, m, temp;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> temp;
		ans.push_back(temp);
	}
	sort(ans.begin(),ans.end());
	
	cin >> m;
	for (int i=0; i<m; i++) {
		cin >> temp;
		cout << upper_bound(ans.begin(),ans.end(),temp) - lower_bound(ans.begin(),ans.end(),temp) << ' ';
	}
}
