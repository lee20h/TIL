#include<iostream>
#include<algorithm>
using namespace std;

int arr[101][101];
int n,m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	int temp1, temp2;
	for (int i=0; i<m; i++) {
		cin >> temp1 >> temp2;
		arr[temp1][temp2] = 1;
		arr[temp2][temp1] = 1;
	}
	
	for (int k=1; k<=n; k++) {
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=n; j++) {
				if(i==j) continue;
				else if(arr[i][k] != 0 && arr[k][j] != 0 ){
					if(arr[i][j] == 0){
						arr[i][j] = arr[i][k] + arr[k][j];
					}
					else {
						arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
					}
				}
			}
		}
	}
	int sum = 0;
	int ans = 2100000000;
	int human;
	for (int i=1; i<=n; i++) {
		for (int j=0; j<=n; j++) {
			sum += arr[i][j];
		}
		if(ans>sum) {
			ans = sum;
			human = i;
		}
		sum = 0;
	}
	cout << human;
}
