// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     It is observed that the minimum number of operations are found only when the target element is the median of 
// the list that is if we will all nuner equal to medain than the number of operations required are minimum. So in 
// this problem we are using nth_element predefined function which will help us to determine the median element of 
// the vector. It works similar to quickselect and result in making the nth element to it's right poisition in the 
// list. Now we have median with us , so now what we are gong to do is that we will check how much we will increase 
// or decrease a number to make it equal to median and store the reult and finally return that one as final answer.

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        
        auto itr=nums.begin()+n/2;
        
        nth_element(nums.begin(),itr,nums.end());
        int median=*itr;
        
        int count=0;
        
        for(int i=0;i<nums.size();i++)
            count+=abs(nums[i]-median);
        
        return count;
        
    }
};