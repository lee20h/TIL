class Solution {
    public boolean isIdealPermutation(int[] A) {
        int max = -1;
        for (int i = 2; i < A.length; i++) {
            max = Math.max(max, A[i - 2]);
            if (max > A[i])
                return false;
        }
        return true;
    }
}