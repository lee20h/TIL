#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<string> v;
	vector<string> v2;
	
	int n, m;
	cin >> n >> m;
	string temp;
	for (int i=0; i<n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(),v.end());
	for (int i=0; i<m; i++) {
		cin >> temp;
		int left = 0;
		int right = n-1;
		while(left <= right) {
			int mid = (left + right) / 2;
			if(v[mid] < temp) {
				left = mid + 1;
			}
			else if(v[mid] > temp) {
				right = mid - 1;
			}
			else {
				v2.push_back(temp);
				break;
			}
		}
	}
	sort(v2.begin(),v2.end());
	cout << v2.size() << '\n';
	for (int i=0; i<v2.size(); i++) {
		cout << v2[i] << '\n';
	}
	
}
