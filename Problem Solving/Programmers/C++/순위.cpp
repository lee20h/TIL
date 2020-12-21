#include <string>
#include <vector>

using namespace std;

bool check[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(auto e: results)
        check[e[0]][e[1]] = true;
    
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if(check[i][k] && check[k][j])
                    check[i][j] = true;
            }
        }
    }
    
    for (int i=1; i<=n; i++) {
        int cnt = 0;
        for (int j=1; j<=n; j++) {
            if(check[i][j] || check[j][i])
                cnt++;
        }
        if(cnt == n-1)
            answer++;
    }
    return answer;
}
