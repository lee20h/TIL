#include <bitset>
using namespace std;

int solution(int n)
{
    int ans = 0;
    bitset<30> bit = n;
    for (int i=0; i<30; i++) {
        if(bit[i])
            ans++;
    }
    return ans;
}
