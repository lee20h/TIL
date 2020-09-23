#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
	vector<int> answer;
        vector<int> tmp;
        vector<pair<int, vector<int>>> vec;
        int i = 0;
        bool flag = false;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '{') continue;
            if (s[j] == '}' || s[j] == ',') {
                if (flag) {
                    int num;
                    if (j - i == 1) num = s[i] - '0';
                    else num = stoi(s.substr(i, j - i));
                    tmp.push_back(num);
                    if (s[j] == '}') { //{} 가 끝났다면
                        vec.push_back(make_pair(tmp.size(), tmp));
                        tmp.clear();
                    }
                    flag = false;
                }
            }
            else {
                if (!flag) { i = j; flag = true; }
            }
        }
        sort(vec.begin(), vec.end());

        set<int> chk;
        for (pair<int, vector<int>> p : vec) {
            for (int num : p.second) {
                // 중복되지 않는 값만 넣어줌.
                if (chk.find(num) == chk.end()) {
                    chk.insert(num);
                    answer.push_back(num);
                }
            }
        }

        return answer;
    }
