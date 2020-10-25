#include <iostream>
#include <vector>
using namespace std;

int dp[2][4];

int solution(vector<vector<int> > land)
{
    int answer = 0;
    for (int i=0; i<4; i++)
        dp[0][i] = land[0][i];
    
    for (int i=1; i<land.size(); i++) {
        dp[i%2][0] = max(max(dp[(i-1)%2][1] + land[i][0], dp[(i-1)%2][2] + land[i][0]),dp[(i-1)%2][3] + land[i][0]);
        dp[i%2][1] = max(max(dp[(i-1)%2][0] + land[i][1], dp[(i-1)%2][2] + land[i][1]),dp[(i-1)%2][3] + land[i][1]);
        dp[i%2][2] = max(max(dp[(i-1)%2][1] + land[i][2], dp[(i-1)%2][0] + land[i][2]),dp[(i-1)%2][3] + land[i][2]);
        dp[i%2][3] = max(max(dp[(i-1)%2][1] + land[i][3], dp[(i-1)%2][2] + land[i][3]),dp[(i-1)%2][0] + land[i][3]);
    }
    
    for (int i=0; i<4; i++) {
        answer = max(answer, dp[(land.size()-1) % 2][i]);
    }
    return answer;
}
