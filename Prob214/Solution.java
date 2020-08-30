// Approach 1:-

class Solution {
    public String shortestPalindrome(String s) {
        String rev_s=new StringBuilder(s).reverse().toString();
        
        String temp= s+"#"+rev_s;
        
        int[] prefixArray=new int[temp.length()];
        
        for(int i=1;i<temp.length();i++) {
            int j=prefixArray[i-1];
            
            while(j>0 && temp.charAt(i)!=temp.charAt(j))
                j=prefixArray[j-1];
            
            if(temp.charAt(i)==temp.charAt(j))
                prefixArray[i]=j+1;
        }
        
        return rev_s.substring(0,s.length()-prefixArray[temp.length()-1])+s;
    }
}