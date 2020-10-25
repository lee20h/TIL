#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int pos[26];

int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char> kf = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    do{
        for(int i=0; i<kf.size(); i++)
            pos[kf[i] - 'A'] = i;
        bool flag = true;
        
        for (int i=0; i<data.size(); i++) {
            int first = data[i][0] - 'A';
            int last = data[i][2] - 'A';
            char oper = data[i][3];
            int diff = data[i][4] - '0';
            int cmp = abs(pos[first] - pos[last]) - 1;
            
            switch(oper) {
                case '=' : 
                    if(cmp != diff)
                        flag = false;
                    break;
                case '<' :
                    if(cmp >= diff)
                        flag = false;
                    break;
                case '>' :
                    if(cmp <= diff)
                        flag = false;
                    break;
            }
            if(!flag)
                break;
        }
        if(flag)
            answer++;
    }while(next_permutation(kf.begin(),kf.end()));
    
    return answer;
}
