class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        int n=days[days.length-1];
        int[] dp=new int[n+1];
        
        for(int i=0,j=1;j<n+1;j++,i++) {
            while(j<n+1 && days[i]!=j) {
                dp[j]=dp[j-1];
                j++;
            }
            
            int one=dp[j-1]+costs[0];
            int seven=dp[Math.max(j-7,0)]+costs[1];
            int thirty=dp[Math.max(j-30,0)]+costs[2];
            
            dp[j]=Math.min(one,Math.min(seven,thirty));            
        }
        
        
        return dp[n];
    }
}