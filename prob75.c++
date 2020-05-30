// https://leetcode.com/problems/sort-colors/3

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     In this we are going to use two pointers approach. Here j represents end of  color while k represents start of 
// 2 color. Now we will itteratethe map and i represents the current element hence when we will encounterc with 0 we 
// will swap it with j inex or on encounter with 2 we will swap it with k . Now an intresting thing to note is that 
// while swap with k we use i-- this is because we don't know thata what this color is hence we have to check it again 
// hence we will again check it hence we wre using this. When i will become greater than k than it represents that the 
// array is sorted hence we can now terminate the loop.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,j=0,k=nums.size()-1;
        
        for(;i<=k;i++)
            if(nums[i]==0)
                swap(nums[i],nums[j++]);
            else
                if(nums[i]==2)
                    swap(nums[i--],nums[k--]);
    }
};