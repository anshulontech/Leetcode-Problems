// Link To Problem:-
// https://leetcode.com/problems/maximum-length-of-pair-chain/

// METHOD 1:-

class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end(), comp);

        int last_val = INT_MIN, count = 0;

        for (int i = 0; i < pairs.size(); i++)
            if (last_val < pairs[i][0])
            {
                last_val = pairs[i][1];
                count++;
            }

        return count;
    }

private:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
};

// METHOD 2:-

class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end());

        int n = pairs.size();

        vector<int> dp(n, 1);

        for (int j = 1; j < n; j++)
            for (int i = 0; i < j; i++)
                if (pairs[i][1] < pairs[j][0])
                    dp[j] = max(dp[j], dp[i] + 1);

        int res = 0;

        for (int i = 0; i < dp.size(); i++)
            if (dp[i] > res)
                res = dp[i];

        return res;
    }
};