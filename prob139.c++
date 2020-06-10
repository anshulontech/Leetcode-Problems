// https://leetcode.com/problems/word-break/

// Time Complexity:-O(N^2).
// Space Complexity:-O(M+N).

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        
        unordered_set<string> store;
        
        for(int i=0;i<wordDict.size();i++)
            store.insert(wordDict[i]);
        
        vector<bool> dp(n+1,false);
        dp[0]=true;
        
        for(int i=1;i<=n;i++) {
            for(int j=0;j<i;j++) {
                string temp=s.substr(j,i-j);
                if(dp[j] && store.find(temp)!=store.end()) {
                    dp[i]=true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};