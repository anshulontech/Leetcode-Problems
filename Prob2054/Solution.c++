// Link To Problem:-
// https://leetcode.com/problems/two-best-non-overlapping-events/

// Solution:-

class Solution
{
public:
    int maxTwoEvents(vector<vector<int>> &events)
    {
        sort(events.begin(), events.end());
        int n = events.size();

        vector<int> maxVal(n);

        maxVal[n - 1] = events[n - 1][2];

        for (int i = n - 2; i >= 0; i--)
            maxVal[i] = max(maxVal[i + 1], events[i][2]);

        int res = maxVal[0];

        for (int i = 0; i < n - 1; i++)
        {
            int idx = binarySearch(events, events[i][1]);
            if (idx < n)
                res = max(res, events[i][2] + maxVal[idx]);
        }

        return res;
    }

    int binarySearch(vector<vector<int>> &events, int val)
    {
        int s = 0, e = events.size();

        while (s < e)
        {
            int m = s + (e - s) / 2;

            if (val >= events[m][0])
                s = m + 1;
            else
                e = m;
        }

        while (s < events.size() && events[s][0] <= val)
            s++;

        return s;
    }
};