// https://leetcode.com/problems/rotate-array/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     In this first we will reverse whole array and than reverse first k characters and than reverse next k characters 
// to get our final result. As we reverse the whole array and than reverse the furst k elements in the array than what 
// happened is that the n-k th element reaches the 0th index and so on we can generate the whole array.

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int N=nums.size();
        
        k%=N;
        
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};