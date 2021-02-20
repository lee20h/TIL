class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        map<char, int> m;
        m.insert({'I', 1});
        m.insert({'V', 5});
        m.insert({'X', 10});
        m.insert({'L', 50});
        m.insert({'C', 100});
        m.insert({'D', 500});
        m.insert({'M', 1000});
        
        for(int i=0; i<s.length()-1; i++) {
            int cur = m[s[i]];
            int next = m[s[i+1]];
            
            cur >= next ? result += cur : result -= cur;
        }
        result += m[s[s.length()-1]];
        return result;
    }
};
