#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	int num;
	int count;
	int temp;
	int min;
	vector<int> score;
	for (int test=1; test<=t; test++) {
		cin >> num;
		count = 1;
		score.clear();
		for (int i=0; i<num; i++) {
			cin >> temp;
			score.push_back(abs(temp));
		}
		sort(score.begin(),score.end());
		min = score[0];
		for (int i=1; i<score.size(); i++) {
			if(min==score[i])
				count++;
		}
		
		cout << "#" << test << ' ' << min << ' ' << count << '\n';
	}
	return 0;
}
