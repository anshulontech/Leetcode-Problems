// https://leetcode.com/problems/contains-duplicate/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     In this we are using an unordered_set to store the aready exist numbers . Now as we will traverse the array 
// we will push numbers to set if they are absent else if they are present than we will return true.

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> store;
        
        for(int i=0;i<nums.size();i++)
            if(store.find(nums[i])!=store.end())
                return true;
            else
                store.insert(nums[i]);
        
        return false;
    }
};