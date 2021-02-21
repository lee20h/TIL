class Solution {
public:
    int brokenCalc(int X, int Y) {
        int result = 0;
        
        while(Y > X) {
            if(Y&1) {
                Y++;
            }
            else {
                Y /= 2;
            }
            result++;
        }
        return result + X - Y;
    }
};
