// Link To The Problem:-
// https://leetcode.com/problems/minimum-average-difference/

// Solution:-

class Solution
{
public:
    int minimumAverageDifference(vector<int> &nums)
    {
        int n = nums.size();
        long long sum = 0;

        for (auto &x : nums)
            sum += x;

        long long currSum = 0;

        long long minAvg = INT_MAX, resIdx = -1;

        for (int i = 0; i < n - 1; i++)
        {
            currSum += nums[i];
            sum -= nums[i];

            long long currAvg = abs(currSum / (i + 1) - sum / (n - i - 1));

            if (currAvg < minAvg)
            {
                minAvg = currAvg;
                resIdx = i;
            }
        }

        currSum += nums[n - 1];
        if (currSum / n < minAvg)
            resIdx = n - 1;

        return resIdx;
    }
};