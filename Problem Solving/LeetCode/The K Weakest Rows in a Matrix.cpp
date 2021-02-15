bool cmp(pair<int,int> &a, pair<int,int> &b) {
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

class Solution {
public:
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> v;
        vector<int> answer;
        for(int i=0; i<mat.size(); i++) {
            int cnt = 0;
            for(int j=0; j<mat[i].size(); j++) {
                if(mat[i][j])
                    cnt++;
            }
            pair<int,int> p;
            p = {cnt, i};
            v.push_back(p);
        }
        sort(v.begin(), v.end(), cmp);
        for (int i=0; i<k; i++) {
            answer.push_back(v[i].second);
        }
        return answer;
    }
};
