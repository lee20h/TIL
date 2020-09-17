#include <iostream>
#include <vector>
#include <stack>
using namespace std;
 
vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && prices[st.top()] > prices[i]) {
            answer[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()) {
        answer[st.top()] = n - st.top() - 1;
        st.pop();
    }
    return answer;
}
