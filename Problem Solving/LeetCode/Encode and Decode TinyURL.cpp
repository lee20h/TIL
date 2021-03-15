class Solution {
public:
    map<string,string> m;
    int key=0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string txt="tinyurl"+to_string(key);
        m[txt]=longUrl;
        key++;
        return txt;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
