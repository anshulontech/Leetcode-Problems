// https://leetcode.com/problems/increasing-subsequences/

// Time Complexity;-O(N^2).
// Space Coplexity;-O(N).
    
// Approach:-
//     We will use simple backtracking and tru=y to operate all the combinations which can form. The speciality of this backtracking 
// process is that during it's execution time the sets which are already considered are not included again in the sln as they are 
// cross checked by the the unordered set. Else Code is clear and easy to understand.

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(nums,res,temp,0);
        
        return res;
    }
    
    void dfs(vector<int> & nums, vector<vector<int>> & res,vector<int> & temp, int start)
    {
        if(temp.size()>1)
            res.push_back(temp);
        
        unordered_set<int> store;
        
        for(int i=start;i<nums.size();i++)
            if((temp.empty() || nums[i]>=temp.back()) && store.find(nums[i])==store.end())
            {
                temp.push_back(nums[i]);
                dfs(nums,res,temp,i+1);
                temp.pop_back();
                store.insert(nums[i]);
            }
    }
};