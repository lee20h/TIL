class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        sort(A.begin(), A.end());
        map<int, long> dp;

        long ret = 0;

        for (int i=0; i<A.size(); i++) {
            dp[A[i]] = 1;
            for (auto it=dp.begin(); it!=dp.end(); it++) {
                if (A[i] % it->first == 0 && dp.count(A[i]/it->first)) {
                    dp[A[i]] = (dp[A[i]] + it->second * dp[A[i]/it->first]) % MOD;
                }
            }
            ret = (ret + dp[A[i]]) % MOD;
        }

        return ret;
    }

};
