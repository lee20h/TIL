class Solution {
public:
    bool isAnagram(string s, string t) {
        int alpha[26], dif[26];
        memset(alpha, 0, sizeof(alpha));
        memset(dif, 0, sizeof(dif));
        if(s.length() != t.length())
            return false;
        
        for (int i=0; i<s.length(); i++) {
            alpha[s[i] - 'a']++;
            dif[t[i] - 'a']++;
        }
        
        for (int i=0; i<26; i++) {
            if(alpha[i] != dif[i])
                return false;
        }
        
        return true;
    }
};
