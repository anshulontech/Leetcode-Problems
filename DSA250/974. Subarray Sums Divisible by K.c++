// Link To The Problem:-
//  https://leetcode.com/problems/subarray-sums-divisible-by-k/

// Solution:-

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        int sum = 0;

        map[0] = 1;

        int res = 0;

        for (auto x : nums)
        {
            sum += x;

            int rem = sum % k;

            if (rem < 0)
                rem += k;

            res += map[rem];
            map[rem]++;
        }

        return res;
    }
};