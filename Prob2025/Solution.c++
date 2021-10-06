// Link To Problem:-
// https://leetcode.com/problems/maximum-number-of-ways-to-partition-an-array/

// Solution:-

class Solution
{
public:
    int waysToPartition(vector<int> &nums, int k)
    {
        int n = nums.size();

        vector<long long> preSum(n, 0), postSum(n, 0);

        preSum[0] = nums[0];
        for (int i = 1; i < n; i++)
            preSum[i] += preSum[i - 1] + nums[i];

        postSum[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            postSum[i] = postSum[i + 1] + nums[i];

        unordered_map<int, pair<int, int>> map;

        for (int i = 0; i < n; i++)
            if (map.find(nums[i]) == map.end())
                map.insert({nums[i], {i, i}});
            else
                map[nums[i]].second = i;

        int res = 0;

        unordered_map<long long, int> right, left;

        for (int i = 0; i < n - 1; i++)
            right[postSum[i + 1] - preSum[i]]++;
        res = right[0];
        for (int i = 0; i < n; i++)
        {

            long long diff = k - nums[i];

            int tempRes = 0;

            tempRes += right[diff];
            tempRes += left[-diff];

            if (i < n - 1)
            {
                int currDiff = postSum[i + 1] - preSum[i];
                right[currDiff]--;
                left[currDiff]++;
            }

            res = max(res, tempRes);
        }

        return res;
    }
};