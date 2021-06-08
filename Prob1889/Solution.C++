// Link To Problem:-
// https://leetcode.com/problems/minimum-space-wasted-from-packaging/

// Solution:-

class Solution
{
public:
    int minWastedSpace(vector<int> &p, vector<vector<int>> &b)
    {
        sort(p.begin(), p.end());
        long long res = LLONG_MAX;
        long long mod = 1e9 + 7;
        long long n = p.size();
        vector<long long> pSum(n + 1, 0);

        for (long long i = 1; i <= n; i++)
            pSum[i] = pSum[i - 1] + p[i - 1];

        for (auto &x : b)
        {
            sort(x.begin(), x.end());
            long long prevIdx = 0;
            long long tempWaste = 0;

            if (p[n - 1] > x[x.size() - 1])
                continue;

            for (auto y : x)
            {
                long long currIdx = upper_bound(p.begin(), p.end(), y) - p.begin();

                long long currSize = pSum[currIdx] - pSum[prevIdx];
                long long len = currIdx - prevIdx;
                long long tempRes = y * len - currSize;
                tempWaste += tempRes;
                // tempWaste%=mod;
                prevIdx = currIdx;
            }

            res = min(res, tempWaste);
        }

        if (res == LLONG_MAX)
            return -1;

        return res % mod;
    }
};