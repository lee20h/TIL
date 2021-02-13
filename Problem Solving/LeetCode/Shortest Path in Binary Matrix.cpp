class Solution {
private:    
    int px[8] = {0, 1, 1, -1, -1, -1, 0, 1};
    int py[8] = {1, 0, 1, 1, 0, -1, -1, -1};
    bool visited[100][100];
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int size = grid.size();
        queue<pair<pair<int,int>,int>> q;
        if(!grid[0][0])
            q.push({{0,0}, 1});
        
        while(!q.empty()) {
            int y = q.front().first.first;
            int x = q.front().first.second;
            int cnt = q.front().second;
            q.pop();
            
            if(y == size-1 && x == size-1) {
                return cnt;
            }
            
            for(int i=0; i<8; i++) {
                int dy = y + py[i];
                int dx = x + px[i];
                
                if(dy < 0 || dx < 0 || dy >= size || dx >= size)
                    continue;
                if(grid[dy][dx] || visited[dy][dx])
                    continue;
                
                q.push({{dy,dx}, cnt+1});
                visited[dy][dx] = true;
            }
        }
        return -1;
    }
};
