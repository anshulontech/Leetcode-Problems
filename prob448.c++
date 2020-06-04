// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     In this what we are going to do is that when we will encountrer with a number than we will make the (num-1) to 
// be negative such that it represents that we have that number in our list. So doing this we will make all (i-1) to 
// be -ve . Now we will again traverse the array and if found any poisitive number tahn it reprsents it's corresponding 
// number that is (i+1) is absent im the list hence we will insert that one to the the list and generate our answer. 

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len=nums.size();
        
        for(int i=0;i<len;i++) {
            int val=abs(nums[i])-1;
            nums[val]=nums[val]>0 ? -nums[val] : nums[val];
        }
        
        vector<int> res;
        
        for(int i=0;i<len;i++)
            if(nums[i]>0)
                res.push_back(i+1);
        
        return res;
    }
};