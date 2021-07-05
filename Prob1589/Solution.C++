// Link To Problem:-
// https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/

// METHOD 1:-

class Solution
{
public:
    int maxSumRangeQuery(vector<int> &nums, vector<vector<int>> &requests)
    {
        int n = nums.size();

        vector<int> count(n + 1, 0);

        for (auto x : requests)
        {
            count[x[0]]++;
            count[x[1] + 1]--;
        }

        int currCount = 0;

        vector<pair<int, int>> freq(n);

        for (int i = 0; i < n; i++)
        {
            currCount += count[i];
            freq[i] = {currCount, i};
        }

        sort(freq.begin(), freq.end());
        sort(nums.begin(), nums.end());

        vector<int> res(n + 1);

        for (int i = 0; i < n; i++)
            res[freq[i].second + 1] = nums[i];

        for (int i = 1; i < n + 1; i++)
            res[i] += res[i - 1];

        long long finalRes = 0, mod = 1e9 + 7;

        for (auto x : requests)
        {
            long long tempSum = res[x[1] + 1] - res[x[0]];
            tempSum %= mod;

            finalRes += tempSum;
            finalRes %= mod;
        }

        return finalRes;
    }
};

// METHOD 2:-

class Solution
{
public:
    int maxSumRangeQuery(vector<int> &nums, vector<vector<int>> &requests)
    {
        int n = nums.size();
        vector<int> count(n + 1, 0);

        for (auto x : requests)
        {
            count[x[0]]++;
            count[x[1] + 1]--;
        }

        for (int i = 1; i < n + 1; i++)
            count[i] += count[i - 1];

        sort(count.begin(), count.end());
        sort(nums.begin(), nums.end());

        long long res = 0, mod = 1e9 + 7;

        for (int i = 0; i < n; i++)
        {
            res = (res + (long)nums[i] * count[i + 1]) % mod;
        }

        return res;
    }
};