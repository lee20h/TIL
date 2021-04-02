class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        int[][] dp = new int[m+1][n+1];
        for (int s = strs.length-1; s>=0;s--) {
            int[] count = count(strs[s]);
            for (int i=m;i>=0;i--) 
                for (int j=n;j>=0;j--) 
                    if (i >= count[0] && j >= count[1]) 
                       dp[i][j] = Math.max(1 + dp[i-count[0]][j-count[1]], dp[i][j]);
        }
        return dp[m][n];
    }

    public int[] count(String str) {
        int[] res = new int[2];
        Arrays.fill(res, 0);
        for (int i=0;i<str.length();i++) {
            if (str.charAt(i) == '0') res[0]++;
            else res[1]++;
        }
        return res;
     }
}