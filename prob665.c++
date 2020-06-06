// https://leetcode.com/problems/non-decreasing-array/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     In this what we are going to do is that if we wiill encounter a situation such that the array will become 
// decreasing than at that point we are going too modify the array. Now we are modifying the array based on condition 1 
// and condition 2 which will tell us that to maintain the which one we have to update .

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int res=0;
        for(int i=1;i<nums.size();i++)
            if(nums[i]<nums[i-1]) {
                res++;
                if(i==1 || nums[i-2]<=nums[i]) // Condition 1
                    nums[i-1]=nums[i];
                else                           // Condition 1
                    nums[i]=nums[i-1];
            }
        
        return res<=1;
    }
};