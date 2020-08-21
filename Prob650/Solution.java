// Approach 1:-

class Solution {
    public int minSteps(int n) {
        
        int[] dp= new int[n+1];
        
        for(int i=2;i<n+1;i++) {
            dp[i]=i;
            
            for(int j=i-1;j>0;j--)
                if(i%j==0) {
                    dp[i]=i/j+dp[j];
                    break;
                }
        }
        
        return dp[n];
    }
}
// Approach 3:-

class Solution {
    public int minSteps(int n) {
        
        for(int i=n-1;i>0;i--)
            if(n%i==0)
                return minSteps(i)+n/i;
        
        return n-1;
    }
}