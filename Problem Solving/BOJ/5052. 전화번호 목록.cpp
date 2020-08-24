#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4+1;

struct Trie{
	Trie* next[10];
	bool term;
	Trie() : term(false) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i=0; i<10; i++) {
			if(next[i])
				delete next[i];
		}
	}
	
	void insert(const char* key) {
		if(*key=='\0')
			term = true;
		else {
			int current = *key - '0';
			if(next[current] == NULL)
				next[current] = new Trie();
			next[current]->insert(key+1);
		}
	}
	
	bool find (const char* key) {
		if(*key == '\0')
			return 0;
		if(term)
			return 1;
		int current = *key - '0';
		return next[current]->find(key+1);
	}
};

char s[MAX][11];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		bool flag = false;
		cin >> n;
		for (int i=0; i<n; i++) {
			cin >> s[i];
		}
		
		Trie *root = new Trie;
		
		for (int i=0; i<n; i++) {
			root->insert(s[i]);
		}
		
		for(int i=0; i<n; i++) {
			if(root->find(s[i]))
				flag = true;
		}
		
		flag ? cout << "NO\n" : cout << "YES\n";
	}
}
