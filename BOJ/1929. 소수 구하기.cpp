#include <iostream>
using namespace std;


bool visited[1000000];
int main() {
	int n, m;
	cin >> n >> m;
	visited[1] = true; 
	for (int i=2; i<m; i++) {
		if(!visited[i]) {
			for (int j=2; j<m; j++) {
				if(i*j > m) break;
				visited[i*j] = true;
			}
		}
	}
	
	for (int i=n; i<=m; i++) {
		if(!visited[i]) {
			cout << i << '\n';
		}
	}
}
