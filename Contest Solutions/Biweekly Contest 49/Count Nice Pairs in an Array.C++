// Solution:-

class Solution
{
public:
    int countNicePairs(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<long long, long long> diff;

        for (int i = 0; i < n; i++)
        {
            int val = reverseNum(nums[i]);

            diff[nums[i] - val]++;
        }

        long long ans = 0, mod = 1e9 + 7;

        for (auto &x : diff)
        {
            long long pair = x.second * (x.second - 1) / 2;
            pair %= mod;
            ans += pair;
            ans %= mod;
        }

        return ans;
    }

private:
    long long reverseNum(int n)
    {
        string s = to_string(n);
        reverse(s.begin(), s.end());

        int idx = 0;
        long long val = 0;
        int k = s.size();

        for (int i = k - 1; i >= 0; i--)
        {
            val += (s[i] - '0') * (pow(10, idx));
            idx++;
        }

        return val;
    }
};