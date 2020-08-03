#include <bits/stdc++.h>
using namespace std;

string dp[101][101];

string sol(string a, string b) {
	long long sum = 0;
	string result;
	
	while(!a.empty() || !b.empty() || sum) {
		if(!a.empty()) {
			sum += a.back() - '0';
			a.pop_back();
		}
		if(!b.empty()) {
			sum += b.back() - '0';
			b.pop_back();
		}
		
		result.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(result.begin(),result.end());
	return result;
}

string combi(int n, int r) {
	if (n == r || r == 0) return "1";
	string &result = dp[n][r];
	if (!result.empty()) return result;
	result = sol(combi(n-1,r-1),combi(n-1,r));
	return result;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n , m;
	cin >> n >> m;
	cout << combi(n,m);
}
