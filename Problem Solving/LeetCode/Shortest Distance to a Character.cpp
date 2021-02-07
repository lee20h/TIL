class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> v, ans;
        for (int i=0; i<s.length(); i++) {
            if(s[i] == c) {
                v.push_back(i);
            }
        }
        int idx= 0;
        for (int i=0; i<s.length(); i++) {
            if(idx != v.size()-1) {
                if(abs(v[idx]-i) >= abs(v[idx+1]-i)) {
                    idx++;
                }
            }
            ans.push_back(abs(i-v[idx]));
        }
        return ans;
    }
};
