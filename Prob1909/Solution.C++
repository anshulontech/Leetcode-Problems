// Link To Problem:-
// https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/

// METHOD 1:-

class Solution
{
public:
    bool canBeIncreasing(vector<int> &nums)
    {
        int i = 0, n = nums.size();

        while (i < n - 1 && nums[i] < nums[i + 1])
            i++;

        if (i == (n - 1))
            return true;

        if (isSorted(nums, i, n) || isSorted(nums, i + 1, n))
            return true;
        else
            return false;
    }

    bool isSorted(vector<int> &nums, int i, int n)
    {
        int prevVal = -1, idx = 0;

        for (; idx < n; idx++)
            if (idx == i)
                continue;
            else
            {
                if (nums[idx] <= prevVal)
                    return false;

                prevVal = nums[idx];
            }

        return true;
    }
};