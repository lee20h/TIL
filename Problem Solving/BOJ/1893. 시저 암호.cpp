#include <bits/stdc++.h>
using namespace std;

const int MAX = 50000 + 1;

int fail[MAX];
/*
	먼저 map 자료구조에 오른쪽으로 shift한 문자들을 넣어놓고 0~a 즉, 모든 경우의 수를 다 찾아본다.
	먼저 새로운 W의 실패함수를 구하고 S에서의 W에 대해 KMP 알고리즘을 시행한다.
	S에서 W를 한번만 찾은 반복문에 대해서만 정답으로 취급해준다. 
*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while(n--) {
		string A, W, S;
		int a, w, s;
		vector<int> v;
		map<char, char> shift; // shift한 문자 결과 
		cin >> A >> W >> S;
		a = A.size();
		w = W.size();
		s = S.size();
		
		for (int i=0; i<a; i++)
			shift[A[i]] = A[(i+1)%a];
		
		for (int circle=0; circle<a; circle++) {
			
			if(circle != 0) {
				for (int i=0; i<w; i++)
					W[i] = shift[W[i]];
			}
			
			memset(fail, 0, sizeof(fail));
			
			for (int i=1, j=0; i<w; i++) { // W의 실패함수 
				while(j > 0 && W[i] != W[j])
					j = fail[j-1];
				if(W[i] == W[j])
					fail[i] = ++j;
			}
			
			bool flag = false; 
			for (int i=0, j=0; i<s; i++) {
				while(j > 0 && S[i] != W[j])
					j = fail[j-1];
				if(S[i] == W[j]) {
					if(j == w-1) {
						if(!flag) {
							flag = true;
							j = fail[j];
						}
						else {
							flag = false;
							break;
						}
					} 
					else
						j++;
				}
			}
			
			if(flag)
				v.push_back(circle);
		}
		
		if(!v.size())
			cout << "no solution\n";
		else if (v.size() == 1)
			cout << "unique: " << v[0] << '\n';
		else {
			cout << "ambiguous: ";
			for (auto x : v)
				cout << x << ' ';
			cout << '\n';
			
		}
	}
}
