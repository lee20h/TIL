#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack<pair<long long,int>> st;
    int m;
    int st_p = 0;
    for (int i=1; i<=heights.size(); i++) {
        m = heights[st_p++];
		while(!st.empty() && st.top().first <= m)
			st.pop();
		if(st.empty()) answer.push_back(0);
		else answer.push_back(st.top().second);
		st.push(make_pair(m,i));
	}
    return answer;
}
