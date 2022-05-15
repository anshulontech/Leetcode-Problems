// Link To The Problem:-
// https://leetcode.com/problems/move-zeroes/

// Solution:-

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int i = 0, j = 0, n = nums.size();

        while (i < n)
        {
            if (nums[i] != 0)
                swap(nums[i], nums[j++]);
            i++;
        }
    }
};