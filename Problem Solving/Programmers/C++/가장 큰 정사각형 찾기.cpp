#include <vector>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    for (int i=0; i<board.size(); i++) {
        answer = max(answer, board[i][0]);
    }
    for (int i=0; i<board[0].size(); i++) {
        answer = max(answer, board[0][i]);
    }
    for (int i=1; i<board.size(); i++) {
        for (int j=1; j<board[i].size(); j++) {
            if(board[i][j]) {
                board[i][j] = min(min(board[i][j-1], board[i-1][j]), board[i-1][j-1]) + 1;
                answer = max(board[i][j], answer);
            }
        }
    }
    return pow(answer,2);
}
