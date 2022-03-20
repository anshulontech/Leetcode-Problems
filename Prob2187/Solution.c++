// Link To The Problem:-
// https://leetcode.com/problems/minimum-time-to-complete-trips/

// Solution:-

class Solution
{
public:
    long long minimumTime(vector<int> &time, long long totalTrips)
    {
        long long start = 0, end = 1e14, res = 0;

        while (start <= end)
        {
            long long mid = start + (end - start) / 2;

            if (numOfTrips(time, mid) >= totalTrips)
            {
                res = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }

        return res;
    }

    long long numOfTrips(vector<int> &time, long long totalTime)
    {
        long long res = 0;

        for (auto x : time)
            res += (totalTime / x);

        return res;
    }

    long long min(long long end, long long time)
    {
        if (end < time)
            return end;
        return time;
    }
};