// Link To The Problem:-
//  https://leetcode.com/problems/maximum-subarray/

// Solution:-

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int minSum = 0, res = nums[0], sum = 0;

        for (auto x : nums)
        {
            sum += x;
            res = max(res, sum - minSum);
            minSum = min(minSum, sum);
        }

        return res;
    }
};