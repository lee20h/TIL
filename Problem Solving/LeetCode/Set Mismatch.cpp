class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> v(2);
        int n = nums.size();
        long long int dif = accumulate(nums.begin(), nums.end(), 0);
        long long int sum = (n * (n+1)) / 2;
        set<int> s;
        for(int i=0; i<n; i++) {
            if(s.find(nums[i]) != s.end()) {
                v[0] = nums[i];
                break;
            }
            s.insert(nums[i]);
        }
        
        v[1] = v[0] - (dif - sum);
        return v;
    }
};
