// https://leetcode.com/problems/longest-continuous-increasing-subsequence/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     In this what we are going to do is that we will calculate the length till which the array is increasing and 
// count it's length . When the array starts to become decreasing we will stop their and than record it's length and 
// check for maximum with the previous value and than again continue the loop till it reaches the end.

class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int N = nums.size() - 1;
        int res = 0;
        int count = 1;
        for (int i = 0; i < N; i++)
            if (nums[i] < nums[i + 1])
                count++;
            else
                res = max(res, count), count = 1;

        return max(res, count);
    }
};