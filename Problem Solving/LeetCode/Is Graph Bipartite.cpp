class Solution {
private:
    int visited[100];
    bool ansFlag;
public:
    void dfs(vector<vector<int>>& graph, int start, int color) {
        if(ansFlag || visited[start])
            return;
        
        visited[start] = color;
        
        for(int i=0; i<graph[start].size(); i++) {
            if(color == visited[graph[start][i]]) {
                ansFlag = true;
                return;
            }
            else if(!visited[graph[start][i]]) {
                if(color == 1)
                    dfs(graph, graph[start][i], 2);
                else
                    dfs(graph, graph[start][i], 1);
            }
        }
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        ansFlag = false;
        memset(visited, 0, sizeof(visited));
        for(int i=0; i<graph.size(); i++) {
            if(!visited[i])
                dfs(graph, i, 1);
        }
        
        return !ansFlag;
    }
};
