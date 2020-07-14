// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/description/

// Time Complexity:-O(N).
// Space Complexity:-O(1).

class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        long N = nums.size(), sum = 0;

        int min_val = INT_MAX;

        for (int i = 0; i < N; i++)
        {
            sum += nums[i];
            min_val = min(min_val, nums[i]);
        }

        return sum - min_val * N;
    }
};