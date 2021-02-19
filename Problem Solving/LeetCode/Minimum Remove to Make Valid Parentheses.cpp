class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        string answer;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else if(s[i] == ')') {
                if(!st.empty())
                    st.pop();
                else
                    s[i] = '+';
            }                
        }
        while(!st.empty()) {
            s[st.top()] = '+';
            st.pop();
        }
        
        for(int i=0; i<s.length(); i++) {
            if(s[i] != '+')
                answer += s[i];
        }
        
        return answer;
    }
};
