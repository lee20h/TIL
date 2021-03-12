class Solution {
public:
    bool hasAllCodes(string str, int k) {
        set<string> s;
        for(int i=0; i+k<=str.size(); i++) {
            s.insert(str.substr(i,k));
        }
        return s.size() == 1 << k;
    }
};
