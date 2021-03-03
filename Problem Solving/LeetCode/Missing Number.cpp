class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long int diff = accumulate(nums.begin(), nums.end(), 0);
        long long int sum = (nums.size() * (nums.size()+1)) / 2;
        return sum - diff;
    }
};
