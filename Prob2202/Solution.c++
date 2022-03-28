// Link To The Problem:-
// https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves/

// Solution:-

class Solution
{
public:
    int maximumTop(vector<int> &nums, int k)
    {
        int n = nums.size();

        if (n == 1)
        {
            if (k % 2 == 1)
                return -1;

            return nums[0];
        }

        if (k > n)
        {
            int maxVal = 0;
            for (auto x : nums)
                maxVal = max(maxVal, x);

            return maxVal;
        }

        int maxVal = -1;

        for (int i = 0; i < k - 1; i++)
        {
            maxVal = max(maxVal, nums[i]);
        }

        if (k < n)
            return max(maxVal, nums[k]);

        return maxVal;
    }
};
