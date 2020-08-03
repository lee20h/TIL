#include <bits/stdc++.h>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	
	for (int t=1; t<=testcase; t++) {
		vector<int> v;
		int temp;
		for (int i=0; i<10; i++) {
			cin >> temp;
			v.push_back(temp);
		}
		int min_ans = 987654321;
		int max_ans = 0;
		for (int i=0; i<10; i++) {
			int sum = 0;
			temp = v[i];
			
			while(temp!=0) {
				sum += temp % 10;
				temp /= 10;
			}
			max_ans = max(sum, max_ans);
			min_ans = min(sum, min_ans);
		}
		cout << "#" << t << ' ' << max_ans << ' ' << min_ans << '\n';
	}
}
