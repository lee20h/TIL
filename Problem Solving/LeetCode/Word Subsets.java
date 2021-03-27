class Solution {
    public List<String> wordSubsets(String[] A, String[] B) {
        List<String> ans = new ArrayList<>();
        int[] find = new int[26];
        for(String tmp : B) {
            int[] count = new int[26];
            for(int i=0; i<tmp.length();i++) {
                count[tmp.charAt(i)-'a']++;
            }
            for(int i=0; i<26; i++) {
                if(count[i] > find[i]) {
                    find[i] = count[i];
                }
            }
        }
        
        for(String tmp : A) {
            int[] check = new int[26];
            for(int i=0; i< tmp.length(); i++) {
                check[tmp.charAt(i)-'a']++;
            }
            
            int flag = 0;
            for(int i=0; i<26; i++){
                if(check[i] < find[i]) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) ans.add(tmp);
        }
        return ans;
    }
}