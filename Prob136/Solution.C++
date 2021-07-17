// Link To Problem:-
// https://leetcode.com/problems/single-number/

// METHOD 1:-

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int i;

        sort(nums.begin(), nums.end());
        for (i = 1; i < nums.size(); i = i + 2)
            if (nums[i - 1] != nums[i])
                return nums[i - 1];

        if (i = nums.size())
            return nums[i - 1];

        return 0;
    }
};

// METHOD 2:-

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
            result ^= nums[i];

        return result;
    }
};