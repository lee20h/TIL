class Solution {
    public int minOperations(int n) {
        int ans = 0;
        int sum = 0;
        int arr[] = new int[n+1];
        for(int i=1; i<=n; i++) {
            arr[i] += 2 * i + 1;
            sum += arr[i];
        }
        int target = sum / n;
        
        for(int i=1; i<=n/2; i++) {
            ans += target - arr[i];
        }
        
        return ans;
    }
}