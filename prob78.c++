// https://leetcode.com/problems/subsets/

// Time Complexity:-O(N*2^N).
// Space Complexity:-O(N*2^N).
    
// Approach:-
//     We will generate all the possible combinations which can be formed and than add them into the result.

class Solution {
private:
    vector<vector<int>> res;
    vector<int> temp;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        res.push_back({});
        for(int i=0;i<nums.size();i++) {
            temp.push_back(nums[i]);
            res.push_back(temp);
            
            helper(nums,temp,i+1);
            
            temp.pop_back();
        }
        
        return res;
    }
    
    void helper(vector<int> & nums,vector<int> & temp,int index) {
        if(index>=nums.size())
            return ;
        
        for(int i=index;i<nums.size();i++) {
            temp.push_back(nums[i]);
            res.push_back(temp);
            
            helper(nums,temp,i+1);
            
            temp.pop_back();
        }
        
        return ;
    }
};