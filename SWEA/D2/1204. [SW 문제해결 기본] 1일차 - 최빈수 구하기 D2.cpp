#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	int testcase;
	cin >> t;
	vector<int> score;
	int count;
	int prev_count;
	int num;
	for (int test=1; test<=t; test++) {
		cin >> testcase;
		count = 1;
		prev_count = 1;
		score.clear();
		for (int i=0; i<1000; i++) {
			cin >> num;
			score.push_back(num);
		}
		sort(score.begin(),score.end());
		for (int i=0; i<1000; i++) {
			if(score[i]==score[i+1])
				count++;
			else {
				if(count >= prev_count) {
					prev_count = count;
					num = score[i];
				}
				count = 1;
				
			}
		}
		if(prev_count < count) {
			prev_count = count;
			num = score[999];
		}
		cout << "#" << test << ' ' << num << '\n';
	}
	return 0;
}
