// Solution:-

class Solution
{
public:
    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        vector<int> sums;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;

            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                sums.push_back(sum);
            }
        }

        sort(sums.begin(), sums.end());

        long long res = 0, mod = 1e9 + 7;

        for (int i = left - 1; i < right; i++)
        {
            res %= mod;
            res += sums[i];
        }

        return res;
    }
};