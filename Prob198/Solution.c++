// Link To Problem:-
// https://leetcode.com/problems/house-robber/

// METHOD 1:-

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);

        vector<int> store(nums.size());

        store[0] = nums[0];
        store[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++)
            store[i] = max(nums[i] + store[i - 2], store[i - 1]);

        return store[nums.size() - 1];
    }
};