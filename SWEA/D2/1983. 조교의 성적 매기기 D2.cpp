#include <iostream>
#include <algorithm>
using namespace std;

int compare(const pair<double,int>& a, const pair<double,int>& b) {
		return a.first > b.first;
}

int main() {
	int t;
	cin >> t;
	int  n, k;
	int pivot;
	vector<pair<double,int>> score;
	string grade[10] = {"A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0"};
	double temp, aver;
	for (int test=1; test<=t; test++) {
		cin >> n >> k;
		for (int i=0; i<n; i++) {
			aver=0;
			cin >> temp;
			aver += temp*0.35;
			cin >> temp;
			aver += temp*0.45;
			cin >> temp;
			aver += temp*0.2;
			
			score.push_back(make_pair(aver,i));
		}
		sort(score.begin(),score.end(),compare);
		pivot = n/10;
		for (int j=0; j<n; j++) {
				if (score[j].second==(k-1)) {
					cout << "#" << test << ' ' << grade[j/pivot] << '\n';
					break;
				}
			}
		score.clear();
	}
	return 0;
}
