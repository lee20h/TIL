#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    queue<string> cache;
    if (cacheSize == 0) {
        answer += 5 * cities.size();
        return answer;
    }

    for (int i = 0; i < cities.size(); i++) {
        bool isHit = false;
        string s = cities[i];

        for (int k = 0; k < s.size(); k++) {
            s[k] = toupper(s[k]);
        }

        int size = cache.size();
        for (int j = 0; j < size; j++) {
            string tmp = cache.front();
            cache.pop();
            if (s.compare(tmp) == 0)
                isHit = true;
            else
                cache.push(tmp);
        }
        if (isHit) { //cache hit
            cache.push(s);
            answer += 1;
        }
        else{ //cache miss
            if (size == cacheSize)
                cache.pop();
            cache.push(s);
            answer += 5;
        }
    }

    return answer;
}
