// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     In this question we are going to use the concept of sliding window concept. We will run a window which will run 
// untill we will encounter 0 ,now on encounter with 0 if we have k as 1 where k represents that you can delete 1 
// element so now we will continue to extend our loop. Now if k!=1 than in that situation we will start to reduce our 
// window till we will not enountered with 0. On encounter with 0 we will remove that from the window and increase k 
// representing that now we can delete a eement from the window and also each step we will check the max length of 
// window that can be formed that is end- start-1  here -1 is necessary because we have to delete one element strictely.

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int start=0,end=0,k=1,len=0;
        
        while(end<nums.size()) {
            if(nums[end]==1)
                end++;
            else
                if(k==1)
                    k--,end++;
                else {
                    while(start<end && nums[start]!=0)
                        start++;
                    
                    start++;
                    k++;
                }
            
            len=max(len,end-start-1);
        }
        
        return len;
    }
};