class Solution {
    public int countSubstrings(String s) {
        if(s.equals("")) {
            return 0;
        }
        
        int ans = 0;
        
        char[] arr = s.toCharArray();
        
        for(int i=0; i<s.length(); i++) {
            String str = Character.toString(arr[i]);
            ans++;
            for(int j=i+1; j<s.length(); j++) {
                str += Character.toString(arr[j]);
                if(str.equals(new StringBuffer(str).reverse().toString()))
                    ans++;
            }
        }
        
        return ans;
    }
}