class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            int temp = nums[i];
            int digit = 0;
            while(temp) {
                temp /= 10;
                digit++;
            }
            if(!(digit&1))
                ans++;
        }
        return ans;
    }
};
