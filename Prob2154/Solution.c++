// Link To The Problem:-
// https://leetcode.com/problems/keep-multiplying-found-values-by-two/

// Solution:-

class Solution
{
public:
    int findFinalValue(vector<int> &nums, int original)
    {
        sort(nums.begin(), nums.end());
        for (auto x : nums)
            if (x == original)
                original *= 2;

        return original;
    }
};