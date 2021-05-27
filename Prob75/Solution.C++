// Link To Problem:-
// https://leetcode.com/problems/sort-colors/3

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int i = 0, j = 0, k = nums.size() - 1;

        for (; i <= k; i++)
            if (nums[i] == 0)
                swap(nums[i], nums[j++]);
            else if (nums[i] == 2)
                swap(nums[i--], nums[k--]);
    }
};