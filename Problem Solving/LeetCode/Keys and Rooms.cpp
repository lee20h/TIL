class Solution {
private:
    bool visited[1001];
public:
    void dfs(int node, vector<vector<int>>& rooms) {
        if(visited[node])
            return;
        visited[node] = true;
        for(int i=0; i<rooms[node].size(); i++) {
            dfs(rooms[node][i], rooms);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        dfs(0, rooms);
        for(int i=0; i<rooms.size(); i++) {
            if(!visited[i])
                return false;
        }
        return true;
    }
};
