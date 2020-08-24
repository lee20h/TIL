#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 3;
char arr[MAX][88];
bool res;
int n, ans;

/*
	단어를 트라이에 입력 하며, NULL 인 곳에 동적할당과 함께 branch를 늘린다.
	다 입력 후 하나하나 다시 보며, 세면 되는데 이 때 경우가 3가지로 나뉜다.
	1. 루트 2. branch 2개이상 3. 가는 도중에 끝나는 단어 포함 
*/
struct Trie {
	bool vaild;
	bool exist;
	int branch;
	Trie* node[26];
	Trie() : vaild(false), exist(false), branch(0) {
		for (int i=0; i<26; i++)
			node[i] = 0;
	}
	~Trie() {
		for (int i=0; i<26; i++)
			if(node[i])
				delete node[i];
	}
	void add(const char* s) {
		if (*s == 0)
			vaild = true;
		else {
			int pos = *s - 'a';
			if (node[pos] == NULL) {
				branch++;
				node[pos] = new Trie();
			}
			exist = true;
			node[pos]->add(s+1);
		}
	}
	void check (const char* s) {
		if(*s == 0)
			return;
		if (res) {
			ans++;
			res = false;
		}
		else {
			if (branch >= 2) ans++;
			else if (vaild) ans++;
		}
		int pos = *s - 'a';
		node[pos]->check(s+1);
	}
};

int main() {
	cout << fixed;
	cout.precision(2);
	while(cin >> n) {
		Trie* root = new Trie();
		for (int i=0; i<n; i++) {
			cin >> arr[i];
			root->add(arr[i]);
		}
		int total = 0;
		for (int i=0; i<n; i++) {
			res = true;
			ans = 0;
			root->check(arr[i]);
			total += ans;
		}
		cout << (double)total / n << '\n';
		delete root;
	}
}
