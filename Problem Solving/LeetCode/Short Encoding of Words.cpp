class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> s(words.begin(), words.end());
        for (string word : words)
            if (s.find(word) != s.end())
                for (int i = 1; i < word.length(); i++) {
                    s.erase(word.substr(i));
                }
        int ans = s.size();
        for (string word : s)
            ans += word.size();
        return ans;
    }
};
