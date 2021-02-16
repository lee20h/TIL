class Solution {
private:
    vector<string> v;
    int dif = 'a' - 'A';
public:
    void solve(string s, int idx, string temp) {
        if(idx == s.length()) {
            v.push_back(temp);
            return;
        }
        
        solve(s, idx+1, temp + s[idx]);
        
        if('a' <= s[idx] && s[idx] <= 'z') {
            char upper = s[idx] - dif;
            solve(s, idx+1, temp + upper);
        }
        else if('A' <= s[idx] && s[idx] <= 'Z') {
            char lower = s[idx] + dif;
            solve(s, idx+1, temp + lower);
        }
    }
    
    vector<string> letterCasePermutation(string S) {
        solve(S, 0, "");
        return v;
    }
};
