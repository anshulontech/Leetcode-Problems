// Link To The Problem:-
// https://leetcode.com/problems/count-array-pairs-divisible-by-k/

// Solution 1:-

class Solution
{
public:
    long long countPairs(vector<int> &nums, int k)
    {
        unordered_map<long long, long long> map;

        long long res = 0;

        for (long long x : nums)
        {
            int currGcd = gcd(x, k);

            for (auto y : map)
                if ((x * y.first) % k == 0)
                    res += y.second;

            map[currGcd]++;
        }

        return res;
    }
};

// Solution 2:-

class Solution
{
public:
    long long countPairs(vector<int> &nums, int k)
    {
        vector<pair<long long, long long>> factorsCount;

        for (long long i = 1; i * i <= k; i++)
            if (k % i == 0)
            {
                factorsCount.push_back({i, 0});

                if (k / i != i)
                    factorsCount.push_back({k / i, 0});
            }

        long long res = 0;

        for (auto x : nums)
        {
            long long currGcd = gcd(x, k);

            for (auto &y : factorsCount)
            {
                if ((currGcd * y.first) % k == 0)
                    res += y.second;

                if (y.first == currGcd)
                    y.second++;
            }
        }

        return res;
    }
};