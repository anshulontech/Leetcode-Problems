// https://leetcode.com/problems/product-of-array-except-self/

// Time Complexity:-O(2*N)~~O(N).
// Space Complexity:-O(N).  No extra space is required except in making an array which we have to return.
    
// Approach:-
//     First we will make an array res of size nums.size() and than assign 0th index of res by 1. Now on moving forward we will 
// first we will store the product of before elements to that poisiton for that index.After the end of the loop similar thing 
// is done while moving from the last and hence the final array obtained is our desired resut.
    
// How:-
//     For i^th index the product is res[i-1] and nums[i-1], hence what is happening here is that it is going to store the 
// product of all numbers occuring before that.Similar phenomena is happening while moving from the end.
    

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        res[0]=1;
        for(int i=1;i<nums.size();i++)
            res[i]=res[i-1]*nums[i-1];
        
        int product=1;
        
        for(int i=nums.size()-1;i>=0;i--)
        {
            res[i]*=product;
            product*=nums[i];
        }
        
        return res;
    }
};