#include <iostream>
#include <vector>
using namespace std;

int v[10001];

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int n;
	cin >> n;
	int temp;
	for (int i=0; i<n; i++) {
		cin >> temp;
		v[temp] += 1;
	}
	for (int i=1; i<=10000; i++) {
		for (int j=0; j<v[i]; j++) {
			cout << i << '\n';
		}
	}
}
