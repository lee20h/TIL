#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    
    for (int i=0; i<moves.size(); i++) {
        int idx = moves[i] - 1;
        int grap = 0;
        
        for (int j=0 ; j<board.size(); j++) {
            if(board[j][idx] == 0) continue;
            
            else {
                grap = board[j][idx];
                if(s.empty() || s.top() != grap)  {
                    s.push(grap);
                }
                else if(s.top() == grap) {
                    answer += 2;
                    s.pop();
                }
                board[j][idx] = 0;
                break;
            }
        }
    }
    return answer;
}
