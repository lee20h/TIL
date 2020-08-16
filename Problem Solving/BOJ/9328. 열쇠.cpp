#include <bits/stdc++.h>
using namespace std;

const int MAX = 100 + 2;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int h,w;
bool visited[MAX][MAX];
bool key[26];
int doc;
string Map[MAX];


void bfs() {
	queue<pair<int,int>> q;
	q.push({0,0});
	
	while(!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if(y < 0 || x < 0 || y > h+1 || x > w+1)
			continue;
		if(visited[y][x] || Map[y][x] == '*' || ('A' <= Map[y][x] && Map[y][x] <= 'Z'))
			continue;
			
		visited[y][x] = true;
		
		if(Map[y][x] == '$') {
			doc++;
			Map[y][x] = '.';
		}
		
		if('a' <= Map[y][x] && Map[y][x] <= 'z') { // ¿­¼è 
			char door = toupper(Map[y][x]);
			Map[y][x] = '.';
			
			if(!key[(door-'A')]) {
				key[door-'A'] = true;
				
				for (int i=1; i<=h; i++) {
					for (int j=1; j<=w; j++) {
						if(Map[i][j] == door)
							Map[i][j] = '.';
					}
				}
				
				memset(visited, false, sizeof(visited));
				
				while(!q.empty())
					q.pop();
					
				q.push({y,x});
				continue;
			}
		}
		
		
		
		for (int i=0; i<4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			q.push({ny,nx});
		
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		memset(key, false, sizeof(key));
		for (int i=0; i<MAX; i++) 
			Map[i].clear();
		memset(visited, false, sizeof(visited));
		
		cin >> h >> w;
		
		for (int i=0; i<w+2; i++) // Å×µÎ¸®¿¡ ºóÄ­À¸·Î Ã¤¿ì±â 
			Map[0] += '.';
			
		for (int i=1; i<=h; i++) {
			string temp;
			cin >> temp;
			Map[i] += '.';
			Map[i] += temp;
			Map[i] += '.';
		}
		
		for (int i=0; i<w+2; i++) // Å×µÎ¸®¿¡ ºóÄ­À¸·Î Ã¤¿ì±â 
			Map[h+1] += '.';
			
		string alpha;
		cin >> alpha;
		
		for (int i=0; i<alpha.length(); i++) {
			if(alpha[i] == '0')
				break;
			
			key[alpha[i] - 'a'] = true;
			for (int y=1; y<=h; y++) {
				for (int x=1; x<=w; x++) {
					if(Map[y][x] == toupper(alpha[i])) {
						Map[y][x] = '.';
					}
				}
			}
		}
		
		doc = 0;
		bfs();
		cout << doc << '\n';
	}
	
	
} 
