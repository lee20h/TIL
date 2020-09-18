#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int solution(vector<vector<int>> board) {
    int answer = 1e9;
    queue<pair<pair<int,int>, pair<int,int>>> q;
    q.push({{0,0},{0,-1}});
    board[0][0] = 1;
    int n = board.size()-1;
    while(!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cost = q.front().second.first;
        int dir = q.front().second.second;
        q.pop();
        if(n == y && n == x) {
            if(answer > cost)
                answer = cost;
        	continue;
        }
        for (int i=0; i<4; i++) {
            int px = dx[i] + x;
            int py = dy[i] + y;
            
            if(px < 0 || py < 0 || px == board.size() || py == board.size() || board[py][px] == 1)
                continue;
                
            int pcost = 0;
			if(dir == -1 || dir == i) 
				pcost = cost + 100;
			else
				pcost = cost + 600;
			
			if(board[py][px] == 0 || board[py][px] >= pcost) {
				board[py][px] = pcost;
				q.push({{py,px},{pcost,i}});
			}
        }
    }
    
    return answer;
}
