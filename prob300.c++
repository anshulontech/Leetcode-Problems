// https://leetcode.com/problems/longest-increasing-subsequence/

// Time Complexity:-O(N^2).
// Space Complexity:-O(N).
    
// Approach:-
//     In this whart we are going to use is the concept of dynamic programming. Here we are initially we are taking 
// an array of size N and store value 1 to all the blocks. Now we are going to traverse the arrayy using two for loops 
// that is we are traversing it twice hence the time complexity would result into N^2. Now let us suppose we are at any 
// index j in array so now we are going to traverse the array from 0 index till j1 index. At each step we are checking 
// that is the value of the jth index will be greater than the ith index or not. If it will than it means that the 
// subsequence till ith index can be expanded by using jth index so we will check that if the increasing the subsequence 
// of ith index with j result in longer one than the previous of j or not. If it will than we will assign in array the 
// ith value +1 . As the array represents the max length of subsequence till that index. After traversing this way we 
// will check that what is the max value and will return that one.
    
    
    
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N=nums.size();
        vector<int> store(N,1);
        
        for(int j=1;j<N;j++)
            for(int i=0;i<j;i++)
                if(nums[j]>nums[i])
                    store[j]=max(store[j],store[i]+1);
        
        int maximum=0;
        
        for(int i=0;i<N;i++)
            if(store[i]>maximum)
                maximum=store[i];
                
        
        
        return maximum;
    }
};