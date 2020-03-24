#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int DP[50010];
int main()
{
	int n;
	int minNum;
	vector<int> v;
 	int MAX = 5000000;
	cin >> n;
	DP[0] = 0;
	DP[1] = 1;
 
	for (int i = 1; i < 230; ++i) {
		v.push_back(i * i);
	}
 
	for (int i = 2; i <= n; ++i) {
		minNum = MAX;
 
		for (int j = 0; v[j] <= i; ++j) {
			int tmp = i - v[j];
			minNum = min(minNum, DP[tmp]);
		}
 
		DP[i] = minNum + 1;
	}
 
	cout << DP[n] << endl;
 
	return 0;
}	
