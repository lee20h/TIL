#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	map<string,string> arr;
	cin >> n >> m;
	string address, pwd;
	for (int i=0; i<n; i++) {
		cin >> address >> pwd;
		arr.insert(make_pair(address,pwd));
	}
	for (int i=0; i<m; i++) {
		cin >> address;
		cout << arr[address] << '\n';
	}
}
