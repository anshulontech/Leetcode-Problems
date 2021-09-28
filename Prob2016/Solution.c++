// Link To Problem:-
// https://leetcode.com/problems/maximum-difference-between-increasing-elements/

// Solution:-

class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> minVal(n), maxVal(n);

        minVal[0] = nums[0];
        maxVal[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++)
            minVal[i] = min(minVal[i - 1], nums[i]);

        for (int i = n - 2; i >= 0; i--)
            maxVal[i] = max(maxVal[i + 1], nums[i]);

        int res = -1;

        for (int i = 0; i < n - 1; i++)
            if (maxVal[i + 1] > minVal[i])
                res = max(res, maxVal[i + 1] - minVal[i]);

        return res;
    }
};