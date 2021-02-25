class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int size = nums.size();
        int left = -1, right = -1;
        int max = -10e5;
        int min = 10e5;
        
        for(int i=0; i<size; i++) {
            if(max < nums[i])
                max = nums[i];
            else if(max > nums[i])
                left = i;
        }
        
        for(int i=size-1; i>=0; i--) {
            if(min > nums[i]) 
                min = nums[i];
            else if(min < nums[i])
                right = i;
        }
        
        if(left == -1)
            return 0;
        return abs(right - left - 1);
    }
};
