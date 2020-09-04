// Approach 1:-

class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        
        int[][] dp=new int[m+1][n+1];
        
        int zeroes,ones;
        
        for(int a=0;a<strs.length;a++) {
            zeroes=0;
            ones=0;
            
            for(int b=0;b<strs[a].length();b++)
                if(strs[a].charAt(b)=='1')
                    ones++;
                else
                    zeroes++;
            
            for(int i=m;i>=zeroes;i--)
                for(int j=n;j>=ones;j--)
                    dp[i][j]=Math.max(dp[i-zeroes][j-ones]+1,dp[i][j]);
        }
        
        return dp[m][n];
    }
}