// Link To The Problem:-
//  https://leetcode.com/problems/k-diff-pairs-in-an-array/

// Solution:-

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        int res = 0;

        unordered_map<int, int> map;

        for (auto x : nums)
            map[x]++;

        for (auto &x : map)
        {
            if (k == 0)
            {
                if (x.second > 1)
                    res++;
            }
            else if (map.find(x.first + k) != map.end())
                res++;
        }

        return res;
    }
};

// Solution 2:-

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int start = 0, end = 0, n = nums.size(), res = 0;

        while (start < n && end < n)
        {
            end = max(start + 1, end);
            while (end < n && nums[end] - nums[start] < k)
                end++;

            if (end < n && ((nums[end] - nums[start]) == k))
                res++;

            int val = nums[start];
            while (start < n && nums[start] == val)
                start++;
        }

        return res;
    }
};