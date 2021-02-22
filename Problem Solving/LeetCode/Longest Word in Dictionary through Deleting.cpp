class Solution {
public:
   bool isSubsequence(string s1, string s2){
      int j = 0;
      for(int i = 0; i < s1.size(); i++){
         if(s2[j] == s1[i]){
            j++;
            if(j == s2.size()) break;
         }
      }
      return j == s2.size();
   }
   string findLongestWord(string s, vector<string>& d) {
      string ans = "";
      for(int i = 0; i < d.size(); i++){
         string x = d[i];
         if(x.size() > ans.size() || (x.size() == ans.size() && (x < ans))){
            if(isSubsequence(s, x)) ans = x;
         }
      }
      return ans;
   }
};
