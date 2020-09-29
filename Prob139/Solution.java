// Approach 1:-

class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> store = new HashSet<String>();
        int n=s.length();
        
        for(String x : wordDict)
            store.add(x);
        
        boolean[] dp = new boolean[n + 1];
        dp[0]=true;
        
        for(int i=1;i<=n;i++)
            for(int j=0;j<i;j++) {
                String temp=s.substring(j,i);
                if(dp[j] && store.contains(temp)) {
                    dp[i]=true;
                    break;
                }
            }
        
        return dp[n];
    }
}