#include <bits/stdc++.h>
using namespace std;

int arr[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int start, end, dist;
		cin >> start >> end >> dist;
		if(arr[start][end] == 0)
			arr[start][end] = dist;
		else 
			arr[start][end] = min(arr[start][end],dist);
	}
	
	for (int k=1; k<=n; k++) {
		for (int i=1; i<=n; i++) {
			    if (arr[i][k] == 0) continue;
			for (int j=1; j<=n; j++) {
				if (arr[k][j] == 0 ||  i == j) continue;
				if(arr[i][j] == 0 || arr[i][k] + arr[k][j] < arr[i][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
	
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	
}
