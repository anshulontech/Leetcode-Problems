// Link To Problem:-
// https://leetcode.com/problems/k-radius-subarray-averages/

// Solution:-

class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        int n = nums.size();

        vector<int> res(n, -1);

        if (2 * k + 1 > n)
            return res;

        long long sum = 0;
        int len = 2 * k + 1;

        for (int i = 0; i < 2 * k + 1; i++)
            sum += nums[i];
        res[k] = sum / len;

        for (int i = k + 1; i < n - k; i++)
        {
            sum += nums[i + k] - nums[i - k - 1];
            res[i] = sum / len;
        }

        return res;
    }
};