class Solution {

    public String[] spellchecker(String[] wordlist, String[] queries) {
    	
    	int n=wordlist.length;
    	int m=queries.length;
    	String[] ans=new String[m];
    	Set<String> st=new HashSet<>();
    	Map<String,Integer> map1=new HashMap<>();
    	Map<String,Integer> map2=new HashMap<>();
    	
    	for(int i=0;i<n;i++) {
    		
    		st.add(wordlist[i]);
    		
    		String s1=wordlist[i].toLowerCase();
    		String s2=change(s1);
    		
    		if(!map1.containsKey(s1))
    			map1.put(s1, i);
    		if(!map2.containsKey(s2))
    			map2.put(s2, i);
    	}
    	
    	for(int i=0;i<m;i++) {
    		if(st.contains(queries[i])) {
    			ans[i]=queries[i];
    			continue;
    		}
    		
    		String s1=queries[i].toLowerCase();
    		String s2=change(s1);
    		
    		if(map1.containsKey(s1))
    			ans[i]=wordlist[map1.get(s1)];
    		else if(map2.containsKey(s2))
    			ans[i]=wordlist[map2.get(s2)];
    		else
    			ans[i]="";
    	}
    	
    	return ans;
    }
    
    private String change(String s) {
    	
    	StringBuilder str=new StringBuilder();
    	
    	for(int i=0;i<s.length();i++) {
    		if(!check(s.charAt(i)))
    			str.append(s.charAt(i));
    		else
    			str.append("#");
    	}
    	
    	return str.toString();
    }
    
    private boolean check(char c) {
    	
    	return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    	
    }
}