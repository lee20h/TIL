#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	vector<string> ans;
	string num;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> num;
		if((num[num.length()-1] - '0')%2==0) ans.push_back("even");
		else ans.push_back("odd");
	}
	for (int i=0; i<n; i++) {
		cout << ans[i] << '\n';
	}
}
