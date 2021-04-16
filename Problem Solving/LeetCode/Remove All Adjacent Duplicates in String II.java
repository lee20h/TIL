class Solution {
    public String removeDuplicates(String s, int k) {
        int cnt = 1;
        for(int i=0; i<s.length()-1; i++) {
            if(s.charAt(i) == s.charAt(i+1))
                cnt++;
            else
                cnt = 1;
            if(cnt == k) 
                s = removeDuplicates(s.substring(0, i - k + 2) + s.substring(i + 2), k);
        }
        return s;
    }
}