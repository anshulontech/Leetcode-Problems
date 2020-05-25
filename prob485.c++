// https://leetcode.com/problems/max-consecutive-ones/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     We will traverse the array from 0th index and as we will encounter we will increase counter representing current 
// consecutive ones by 1 else if we will encounter with 0 than we will check that which is max res or counter and update 
// the res . At last we will return max of res and counter as if the max continues one are present in last than it will 
// not update the res at that time using nums[i]==0 condition.

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0,counter=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
            if(nums[i]==1)
                counter++;
            else {
                res=max(res,counter);
                counter=0;
            }
        
        return max(res,counter);
    }
};