#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 100000 + 1;
int a[MAX], arr[MAX];
pair<int, int> b[MAX];
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
    int n;
	cin >> n;
    for (int i = 0; i < n; i++)
		cin >> a[i];
    for (int i = 0; i < n; i++) {
        int input;
		cin >> input;
        b[i] = {input, i};
    }
    
	sort(b, b + n);
	
    for (int i = 0; i < n; i++)
        arr[i] = b[a[i] - 1].second;
 
    vector<int> vec;
 
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
 
        if (idx >= vec.size()) vec.push_back(arr[i]);
        else vec[idx] = arr[i];
 
    }
 
    cout << vec.size();
}

