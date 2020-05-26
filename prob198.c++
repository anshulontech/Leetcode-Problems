// https://leetcode.com/problems/house-robber/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     In this we are going to make a dp array which will tell us that what is the max number of money we can steel 
// if we are robbing i+1 houses. In this table we are setting the first 2 elements than moving forward. Now let we are 
// at i index than we will check that is robbing current house + robbing i-2 houses will make more money than robbing 
// just i-1 houses or not . If it will than we update value of i th house  to be new one else just robbing i-1 houses 
// and leaving that house.

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        
        
        vector<int> store(nums.size());
        
        store[0]=nums[0];
        store[1]=max(nums[0],nums[1]);
        
        for(int i=2;i<nums.size();i++)
            store[i]=max(nums[i]+store[i-2],store[i-1]);
        
        return store[nums.size()-1];
        
    }
};