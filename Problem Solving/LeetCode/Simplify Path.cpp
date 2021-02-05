class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        string temp, ans;
        for(int i=0; i<path.length(); i++) {
            if(path[i] == '/') {
                if(temp == ".") {
                    temp.clear();
                    continue;
                }
                else if(temp == "..") {
                    if(v.size())
                        v.pop_back();
                }
                else if(!temp.empty()) {
                    v.push_back(temp);
                }
                temp.clear();
            } else {
                temp += path[i];
            }
        }
        if(path[path.length()-1] != '/') {
            if(temp == "..") {
                if(v.size())
                    v.pop_back();
            }
            else if(!temp.empty() && temp != ".") {
                v.push_back(temp);
            }
        }
        for (int i=0; i<v.size(); i++)
            ans += '/' + v[i];
        if(ans.empty())
            ans = '/';
            return ans;
        }
};
