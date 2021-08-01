// Solution:-

class Solution
{
public:
    int countSpecialSubsequences(vector<int> &nums)
    {
        int n = nums.size();
        long long mod = 1e9 + 7;

        vector<long long> for0(n + 2, 0), for1(n + 2, 0), for2(n + 2, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] == 0)
                for0[i] = ((for0[i + 1] * 2) % mod + for1[i + 1] % mod) % mod;
            else
                for0[i] = for0[i + 1];

            if (nums[i] == 1)
                for1[i] = ((for1[i + 1] * 2) % mod + for2[i + 1] % mod) % mod;
            else
                for1[i] = for1[i + 1];

            if (nums[i] == 2)
                for2[i] = (for2[i + 1] * 2 + 1) % mod;
            else
                for2[i] = for2[i + 1];
        }

        return for0[0] % mod;
    }
};