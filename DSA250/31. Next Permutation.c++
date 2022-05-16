// Link To The Problem:-
//  https://leetcode.com/problems/next-permutation/

// Solution:-

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 1;

        while (i > 0 && nums[i - 1] >= nums[i])
            i--;

        if (i == 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        reverse(nums.begin() + i, nums.end());

        int idx = upper_bound(nums.begin() + i, nums.end(), nums[i - 1]) - nums.begin();

        swap(nums[idx], nums[i - 1]);
    }
};