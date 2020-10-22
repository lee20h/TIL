#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int sum = 0;
    int temp = x;
    while(x) {
        sum += x%10;
        x/=10;
    }
    if(temp%sum)
        answer = false;
    return answer;
}
