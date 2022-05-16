// Link To The Problem:-
//  https://leetcode.com/problems/subarray-sum-equals-k/

// Solution:-

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int res = 0;

        unordered_map<int, int> map;

        map[0] = 1;

        int sum = 0;

        for (auto x : nums)
        {
            sum += x;

            res += map[sum - k];

            map[sum]++;
        }

        return res;
    }
};