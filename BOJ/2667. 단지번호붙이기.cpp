#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> home[25];
bool visited[25][25];
vector<int> cnt;
int n;
int pos1[4] = {0,0,-1,1};
int pos2[4] = {1,-1,0,0};
int cnt_ = 1;

int dfs(int y,int x) {
	if(!visited[y][x]) {
		visited[y][x] = true;
		for (int i=0; i<4; i++) {
			int xpos = x + pos1[i];
			int ypos = y + pos2[i];
			
			if(xpos<0 || xpos>=n || ypos<0 || ypos>=n){
				continue;
			}
			if(home[ypos][xpos] == '0') {
				continue;
			}
			if(visited[ypos][xpos]) {
				continue;
			}
			if (!visited[ypos][xpos]){
				cnt_++;
				dfs(ypos,xpos);
			}
		}
	}
	return cnt_;
}

int main() {
	char temp;
	cin >> n;
	
	for (int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> temp;
			home[i].push_back(temp);
		}
	}
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if(home[i][j] == '1' && !visited[i][j]) {
				cnt.push_back(dfs(i,j));
				cnt_ = 1;
			}
		}
	}
	cout << cnt.size() << '\n';
	sort(cnt.begin(),cnt.end());
	for (int i=0; i<cnt.size(); i++) {
		cout << cnt[i] << '\n';
	}
	
}
