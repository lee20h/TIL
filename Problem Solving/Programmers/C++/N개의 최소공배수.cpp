#include <string>
#include <vector>
#include <queue>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int solution(vector<int> arr) {
    int answer = 0;
    int mul = 1;
    priority_queue<int> q;
    for (int i=0; i<arr.size(); i++) {
        mul *= arr[i];
        q.push(arr[i]);
    }
    while(q.size() != 1) {
        int num1 = q.top();
        q.pop();
        int num2 = q.top();
        q.pop();
        q.push(num1*num2/gcd(num1,num2));
    }
    answer = q.top();
    return answer;
}
