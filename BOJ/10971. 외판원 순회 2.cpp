#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[10];



int main() {
	int n;
	cin >> n;
	int temp;
	int sum=0;
	int mini=2100000000;
	vector<int> w(n);
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> temp;
			v[i].push_back(temp);
		}
	}
	
	for (int i=0; i<n; i++)
		w[i] = i;
	
	do {
		bool no = false;
		sum = 0;
		for (int i=0; i<n-1; i++) {
			if(v[w[i]][w[i+1]] == 0) {
				no = true;
			}
			else {
				sum += v[w[i]][w[i+1]];
			}
		}
		if(!no && v[w[n-1]][w[0]] != 0) {
			sum += v[w[n-1]][w[0]];
			mini = min(mini,sum);
		}
	
		
	}while(next_permutation(w.begin(),w.end()));
	cout << mini;
}
