// https://leetcode.com/problems/maximum-product-subarray/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     Using the curr_max and curr_min we are going to store the max and min value till that number. The min number 
// is store as that if two -ve number ssare present than we have to make think of about them . Now if a zero will be 
// encountered than al numbers will automatically become equal to zero and a new array will start from there.

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0)
            return -1;
        
        int curr_max=0;
        int curr_min=nums[0];
        int final_max=nums[0];
        
        for(int i=1;i<nums.size();i++) {
            int temp=curr_max;
            curr_max=max(max(curr_max*nums[i],curr_min*nums[i]),nums[i]);
            
            curr_min=min(min(temp*nums[i],curr_min*nums[i]),nums[i]);
            
            final_max=max(final_max, curr_max);
        }
        
        return final_max;
    }
};