#include <string>
#include <vector>
#include <bitset>
using namespace std;

int solution(int n) {
    int answer = 0;
    bitset<20> bit;
    bit = n;
    int one = 0;
    for (int i=0; i<bit.size(); i++) {
        if(bit[i]==1)
            one++;
    }
    int cmp;
    while(++n) {
        cmp = 0;
        bit = n;
        for (int i=0; i<bit.size(); i++) {
            if(bit[i]==1)
                cmp++;
        }
        if(one == cmp) {
            answer = n;
            break;
        }
    }
    return answer;
}
