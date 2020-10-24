#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end(),cmp);
    int answer = 0;
    
    int weight;
    int left = 0, right = people.size()-1;
    
    while(left<right) {
        weight = people[left]+people[right];
        if(weight <= limit)
            left++, right--;
        else
            left++;
        answer++;
    }
    if(left==right)
        answer++;
    return answer;
}
