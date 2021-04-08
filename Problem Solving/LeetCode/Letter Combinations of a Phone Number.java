class Solution {
    public List<String> letterCombinations(String digits) {
        LinkedList<String> ret = new LinkedList<String>();
        if(digits.isEmpty()) return ret;
        String[] mapping = new String[]{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        ret.add("");
        while(ret.peek().length()!=digits.length()){
            String remove = ret.remove();
            String map = mapping[digits.charAt(remove.length())-'0'];
            for(char c: map.toCharArray()){
              ret.addLast(remove+c);
            }
        }
        return ret;
    }
}