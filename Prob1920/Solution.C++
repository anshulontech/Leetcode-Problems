// Link To Problem:-
// https://leetcode.com/problems/build-array-from-permutation/

// METHOD 1:-

class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n);

        for (int i = 0; i < n; i++)
            res[i] = nums[nums[i]];

        return res;
    }
};

// METHOD 2:-

class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
            nums[i] = nums[i] + (n * (nums[nums[i]] % n));

        for (auto &x : nums)
            x /= n;

        return nums;
    }
};