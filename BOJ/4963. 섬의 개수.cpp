#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int> land[50];
bool visited[50][50];
int pos1[8] = {-1,-1,-1,0,0,1,1,1};
int pos2[8] = {-1,0,1,-1,1,-1,0,1};
int w, h;
int cnt=0;
void dfs(int y, int x) {
	if(!visited[y][x]) {
		visited[y][x] = true;
		for (int i=0; i<8; i++) {
			int ypos = y + pos1[i];
			int xpos = x + pos2[i];
			
			if (xpos < 0 || xpos >= w || ypos < 0 || ypos >=h) {
				continue;
			}
			if (land[ypos][xpos] == 0)
				continue;
			
			if(!visited[ypos][xpos]) {
				dfs(ypos,xpos);
			}
		}
	}
		
	
	
}

int main() {
	int temp;
	while(1) {
		cnt = 0;
		cin >> w >> h;
		if(w==0 && h==0)
			break;
		memset(visited,0,sizeof(visited));
		for (int i=0; i<h; i++)
			land[i].clear();
		for(int i=0; i<h; i++) {
			for (int j=0; j<w; j++){
				cin >> temp;
				land[i].push_back(temp);
			}
		}
		for (int i=0; i<h; i++) {
			for (int j=0; j<w; j++) {
				if (land[i][j] == 1 && !visited[i][j]) {
					dfs(i,j);
					cnt++;
				}
					
			}
		}
		cout << cnt << '\n';	
	}
	
	
}
