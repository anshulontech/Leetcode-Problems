// Link To The Problem:-
//  https://leetcode.com/problems/first-missing-positive/

// Solution:-

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        for (auto &x : nums)
            if (x <= 0)
                x = INT_MAX - 2;

        int n = nums.size();
        bool isN = false;

        for (auto x : nums)
        {
            if (abs(x) == n)
                isN = true;
            if (abs(x) >= n)
                continue;

            if (nums[abs(x)] < 0)
                continue;
            else
                nums[abs(x)] *= -1;
        }

        for (int i = 1; i < n; i++)
            if (nums[i] > 0)
                return i;

        return n + isN;
    }
};

/*

    1   2   3

*/