class Solution {
    public int threeSumMulti(int[] arr, int target) {
        int MOD = 1000000007;
        int count = 0;
        for (int i=0; i<arr.length; i++) {
            int temp = getPairsCount(arr.length, target-arr[i], arr, i+1);
            count = (count+temp)%MOD;
        }
        return count;
    }
    
    public int getPairsCount(int n, int sum, int[] arr, int start) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i=start; i<n; i++) {
            map.put(arr[i], map.getOrDefault(arr[i], 0)+1);
        }

        int count = 0;
        for (int i=start; i<n; i++) {
            if(map.get(sum-arr[i]) != null) {
                count += map.get(sum - arr[i]);
            }

            if (sum-arr[i] == arr[i]) {
                count--;
            }
        }

        return count/2;
    }
}