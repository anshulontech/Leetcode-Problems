// Link To The Problem:-
// https://leetcode.com/problems/find-pivot-index/

// Solution:-

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int sum = 0;

        for (auto x : nums)
            sum += x;

        int lsum = 0, n = nums.size();

        for (int i = 0; i < n; i++)
        {
            sum -= nums[i];

            if (lsum == sum)
                return i;

            lsum += nums[i];
        }

        return -1;
    }
};
