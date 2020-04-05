// https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/

// Time Complexity:-O(nlog(n)+n).
// Space Complexity:-O(n).

// Approach:-
// Initially we will sort the array and define a vector named A. Now we will first calculate the sum of whole array and than 
// itterate the whole loop from the rear side and also updatig the value of temp. The loop runs untill temp<=sum/2 or i>=0.

// Actually what happens with itterating the loop from rear side is that when we itterate the loop from rear side we are 
// considering the maximun values hence we can say that we can reach the target condition in less amount of time and also 
// by taking less number of variables.

// Now as loop runs we keep on updating the value of temp by just adding nums[i] to it and also adding nums[i] to the vector A.
// At last we return the vector A which represents the output result what we want.



class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        
        vector<int> A;
        sort(nums.begin(),nums.end());
        
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        
        int temp=0;
        for(int i=nums.size()-1;i>=0&&temp<=sum/2;i--)
        {
            A.push_back(nums[i]);
            temp+=nums[i];
        }
        
        return A;
    }
};