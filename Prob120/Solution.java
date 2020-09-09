// Approach 1:-

class Solution {
    private int res=0;
    public int minimumTotal(List<List<Integer>> triangle) {
        res+=triangle.get(0).get(0);
        
        res+=helper(triangle,1,0);
        
        return res;
    }
    
    private int helper(List<List<Integer>> triangle,int row,int index) {
        if(row>=triangle.size())
            return 0;
        
        
        int first=triangle.get(row).get(index)+helper(triangle,row+1,index);
        int second=triangle.get(row).get(index+1)+helper(triangle,row+1,index+1);
            
        return Math.min(first,second);       
    }
}

// Approach 2:-

class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        
        int n=triangle.size();
        int[] dp = new int[n+1];
        
        for(int i=n-1;i>=0;i--)
            for(int j=0;j<=i;j++)
                dp[j]=Math.min(dp[j],dp[j+1])+triangle.get(i).get(j);
        
        return dp[0];
    }
}