#include <string>
#include <vector>

using namespace std;

const int MOD = 1e9+7;

int solution(int n) {
    int prev = 1;
    int cur = 1;
    for (int i=0; i<n-1; i++) {
        int temp = (prev + cur) % MOD;
        prev = cur;
        cur = temp;
    }
    return cur;
}
