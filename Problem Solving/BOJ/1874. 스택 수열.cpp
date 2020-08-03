#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
    int n;
    vector<int> v;
    stack<int> s;
    vector<char> d;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        v.push_back(k);
    }
    vector<int>::iterator it;
    it = v.begin();
    for (int i = 1; i <= n; i++) {
        s.push(i);
        d.push_back('+');
        while (!s.empty()) {
            if (*it != s.top()) break;
            else {
                s.pop();
                d.push_back('-');
                it++;
            }
        }
    }
    if (s.empty()) {
    for(int i=0 ;i<d.size() ; i++) 
        cout<<d[i]<<"\n";
    }
    else cout << "NO";
}
