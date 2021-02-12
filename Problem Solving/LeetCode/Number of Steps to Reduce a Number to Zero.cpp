class Solution {
public:
    int numberOfSteps (int num) {
        int answer = 0;
        while(num) {
            if(num & 1)
                num--;
            else
                num /= 2;
            answer++;
        }
        return answer;
    }
};
