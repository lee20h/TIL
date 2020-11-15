#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool check_minimality(const vector<int> &keys, const int bit) {
    for (int i=0; i<keys.size(); i++) {
        if((keys[i] & bit) == keys[i]) {
            return false;
        }
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    vector<int> keys;
    int cnt = 0;
    int tupleSize = relation.size();
    int columnSize = relation[0].size();
    
    for (int bit=1; bit < (1 << columnSize); bit++) {
        if(!check_minimality(keys, bit))
            continue;
        unordered_set<string> s;
        
        for (int i=0; i<tupleSize; i++) {
            string key;
            for (int j=0; j<columnSize; j++) {
                if(bit & (1 << j)) {
                    key += relation[i][j] + ' ';
                }
            }
            s.insert(key);
        }
        
        if(s.size() == tupleSize) {
            keys.push_back(bit);
            cnt++;
        }
    }
    
    
    return cnt;
}
