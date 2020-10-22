#include <iostream>
#include <string>
 
using namespace std;
 
string solution(string number, int k) {
    string answer = "";
    for (int i = 0, index = -1; i < number.length() - k; i++) {
        char max = 0;
        for (int j = index + 1; j <= k + i; j++) {
            if (max < number[j]) {
                index = j;
                max = number[j];
            }
        }
        answer += max;
    }
    return answer;
}
