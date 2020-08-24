#include <bits/stdc++.h>
using namespace std;

set<string> ans;
int dx[] = {0,0,-1,-1,-1,1,1,1};
int dy[] = {-1,1,-1,0,1,-1,0,1};
int scoreboard[] = {0,0,0,1,1,2,3,5,11};
bool visited[4][4];
string boggle[4];

/*
	주어진 단어들을 트라이에 저장한 후 Boggle 보드에서 브루트포스를 통해 모든 문자열을 set에 저장한 뒤 출력한다
	 
*/
struct Trie {
	bool finish;
	Trie* next[26];
	Trie() : finish(false) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for(int i=0; i<26; i++)
			if(next[i])
				delete next[i];
	}
	
	void insert(const char* key) {
		if (*key == '\0')
			finish = true;
		else {
			int cur = *key - 'A';
			if(next[cur] == NULL)
				next[cur] = new Trie();
			next[cur]->insert(key + 1);
		}
	}
	
	void query(int y, int x, string cur) {
		if (y<0 || x<0 || y==4 || x==4 || visited[y][x])
			return;
		if(cur.size() >= 8)
			return;
		
		visited[y][x] = true;
		cur = cur + boggle[y][x];
		if (next[boggle[y][x] - 'A'] == NULL) {
			visited[y][x] = false;
			return;
		}
		
		if(next[boggle[y][x] - 'A']->finish)
			ans.insert(cur);
		for (int i=0; i<8; i++) {
			next[boggle[y][x] - 'A']->query(y + dy[i], x + dx[i], cur);
		}
		visited[y][x] = false;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	Trie *root = new Trie;
	int w, b;
	cin >> w;
	for (int i=0; i<w; i++) {
		char c[9];
		cin >> c;
		root->insert(c);
	}
	cin >> b;
	
	for (int i=0; i<b; i++) {
		ans.clear();
		for (int j=0; j<4; j++) 
			cin >> boggle[j];
		
		for (int j=0; j<4; j++) {
			for (int k=0; k<4; k++) {
				root->query(j, k, "");
			}
		}
		
		string longstr = *(ans.begin());
		int score = 0;
		for (auto it : ans) {
			if(longstr.size() < it.size())
				longstr = it;
			score += scoreboard[it.size()];
		}
		cout << score << ' ' << longstr << ' ' << ans.size() << '\n';
	}
}
