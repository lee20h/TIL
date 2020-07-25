#include <string>
using namespace std;

bool visited[11][11][11][11];

int solution(string dirs) {
    int answer = 0;
    int xpos = 5;
    int ypos = 5;
    for (int i=0; i<dirs.size(); i++) {
        char cmd = dirs[i];
        if (cmd == 'L') {
            if(xpos > 0) {
                if(!visited[xpos][ypos][xpos-1][ypos]){
                    answer++;
                    visited[xpos][ypos][xpos-1][ypos] = true;
                    visited[xpos-1][ypos][xpos][ypos] = true;
                }
                xpos--;
            }
        }
        else if (cmd == 'U') {
            if(ypos < 10) {
                
                if(!visited[xpos][ypos][xpos][ypos+1]){
                    answer++;
                    visited[xpos][ypos][xpos][ypos+1] = true;
                    visited[xpos][ypos+1][xpos][ypos] = true;
                }
                ypos++;
            }
        }
        else if (cmd == 'R') {
            if(xpos < 10) {
                
                if(!visited[xpos][ypos][xpos+1][ypos]){
                    answer++;
                    visited[xpos][ypos][xpos+1][ypos] = true;
                    visited[xpos+1][ypos][xpos][ypos] = true;
                }
                xpos++;
            }
        }
        else if (cmd == 'D') {
            if(ypos > 0) {
                
                if(!visited[xpos][ypos][xpos][ypos-1]){
                    answer++;
                    visited[xpos][ypos][xpos][ypos-1] = true;
                    visited[xpos][ypos-1][xpos][ypos] = true;
                }
                ypos--;
            }
        }
    }
    return answer;
}
