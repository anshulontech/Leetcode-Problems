// Approach 1:-

class Solution {
    public boolean canPartition(int[] nums) {
        int n=nums.length;
        int totalSum=0;
        
        for(int i=0;i<n;i++)
            totalSum+=nums[i];
        
        if(totalSum%2!=0)
            return false;
        
        int halfSum=totalSum/2;
        
        boolean[][] dp = new boolean[n+1][halfSum+1];
        
        for(int i=0;i<n+1;i++)
            Arrays.fill(dp[i],false);
        
        for(int i=1;i<n+1;i++)
            dp[i][0]=true;
        
        for(int i=1;i<n+1;i++) {
            for(int j=1;j<halfSum+1;j++)
                dp[i][j]=dp[i-1][j] || (j>=nums[i-1] ? (dp[i-1][j-nums[i-1]]) : false );
            
            if(dp[i][halfSum])
                return true;
        }
        
        
        return false;
    }
}

// Approach 2:-

class Solution {
    public boolean canPartition(int[] nums) {
        int n=nums.length;
        int totalSum=0;
        
        for(int i=0;i<n;i++)
            totalSum+=nums[i];
        
        if(totalSum%2!=0)
            return false;
        
        int halfSum=totalSum/2;
        
        boolean[] dp = new boolean[halfSum+1];
        Arrays.fill(dp,false);
        
        dp[0]=true;
        
        for(int i=0;i<n;i++) {
            for(int j=halfSum;j>=nums[i];j--)
                dp[j]=dp[j] || dp[j-nums[i]];
            
            if(dp[halfSum])
                return true;
        }
        
        return false;
    }
}