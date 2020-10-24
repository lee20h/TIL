#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int size = brown + yellow;
    vector<int> divisor;
    for (int i=1; i<size; i++) {
        if(size%i == 0) {
            divisor.push_back(i);
        }
    }
    
    int w, h;
    for (int i=divisor.size()-1; i>0; i--) {
        bool flag = false;
        w = divisor[i];
        for (int j=divisor.size()-1; j>0; j--) {
            h = divisor[j];
            if(w*h == size) {
                int temp = w*2 + (h-2)*2;
                if(brown != temp)
                    continue;
                flag = true;
                answer.push_back(w);
                answer.push_back(h);
                break;
            }
        }
        if(flag)
            break;
    }
    return answer;
}
