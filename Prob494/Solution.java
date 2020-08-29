// Approach 1:-

class Solution {
    private int res=0,negativeSum=0,currSum=0;
    
    public int findTargetSumWays(int[] nums, int S) {
        int totalSum=0;
        for(int i=0;i<nums.length;i++)
            totalSum+=nums[i];
        
        negativeSum=totalSum-S;
        
        if(negativeSum==0)
            res++;
        
        if(negativeSum%2!=0)
            return 0;
        else
            negativeSum/=2;
        
        for(int i=0;i<nums.length;i++) {
            currSum+=nums[i];
            helper(nums,i+1);
            currSum-=nums[i];
        }
        
        return res;
    }
    
    private void helper(int[] nums,int index) {
        if(currSum>negativeSum)
            return ;
        
        if(currSum==negativeSum)
            res++;
        
        for(int i=index;i<nums.length;i++) {
            currSum+=nums[i];
            helper(nums,i+1);
            currSum-=nums[i];
        }
        
        return ;
    }
}

// Approach 2:-

class Solution {
    public int findTargetSumWays(int[] nums, int S) {
       int totalSum=0;
        
        int sum=0;
        
        for(int n : nums) 
            sum+=n;
        
        return sum<S || (S+sum)%2!=0 ? 0 : subsetSum(nums,(S+sum)/2);
        
    }
    
    private int subsetSum(int[] nums,int sum) {
        int[] dp=new int[sum+1];
        dp[0]=1;
        
        for(int n:nums)
            for(int i=sum;i>=n;i--) {
                dp[i]+=dp[i-n];
            }
        return dp[sum];
    }
}