// Link To The Problem:-
// https://leetcode.com/problems/minimum-time-to-finish-the-race/

// Solution:-

class Solution
{
public:
    int minimumFinishTime(vector<vector<int>> &tires, int changeTime, int numLaps)
    {
        vector<long long> dp(numLaps + 1, LLONG_MAX);
        dp[0] = 0;

        for (auto &x : tires)
        {
            long long f = x[0], r = x[1], lastLapTime = f, totalTime = f, lapCount = 2;
            dp[1] = min(dp[1], f);

            while (lastLapTime * r < f + changeTime)
            {
                long long currentLapTime = lastLapTime * r;
                totalTime += currentLapTime;
                dp[lapCount] = min(dp[lapCount], totalTime);
                lastLapTime = currentLapTime;
                lapCount++;
            }
        }

        for (long long i = 0; i < numLaps + 1; i++)
            for (long long j = 1; j <= i; j++)
                dp[i] = min(dp[i], dp[j] + changeTime + dp[i - j]);

        return dp[numLaps];
    }
};