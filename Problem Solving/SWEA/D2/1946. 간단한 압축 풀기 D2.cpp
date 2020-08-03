#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	int n;
	char ci;
	int ki;
	int width;
	vector<string> result;
	string a;
	for (int test=1; test<=t; test++) {
		cin >> n;
		result.clear();
		a.clear();
		width=0;
		for (int i=0; i<n; i++) {
			cin >> ci >> ki;
			for (int j=0; j<ki; j++) {
				a += ci;
				width++;
				if (width == 10) {
					width = 0;
					result.push_back(a);
					a.clear();
				}
			}
		}
		result.push_back(a);
		cout << "#" << test << '\n';
		for (int i=0; i<result.size(); i++) {
			cout << result[i] << '\n';
		}
	}
	return 0;
}
