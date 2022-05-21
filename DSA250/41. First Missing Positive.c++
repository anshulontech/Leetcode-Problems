// Link To The Problem:-
//  https://leetcode.com/problems/first-missing-positive/

// Solution 1:-

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

// Solution 2:-

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);

        for (int i = 0; i < n; i++)
            if (nums[i] != i + 1)
                return i + 1;

        return n + 1;
    }
};