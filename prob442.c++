// https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     We will traverse the array and on each encounter with a number we will make the corresponding number to it's 
// negative . Now if After making it negative it remains poisitive than we cnclude that this index already occured 
// in the array hence we ill add that to result.

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();i++) {
            nums[abs(nums[i])-1]*=-1;
            
            if(nums[abs(nums[i])-1]>0)
                res.push_back(abs(nums[i]));
        }
        
        return res;
    }
};