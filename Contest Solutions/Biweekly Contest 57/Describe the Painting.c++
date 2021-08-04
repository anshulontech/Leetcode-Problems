// Solution:-

class Solution
{
public:
    vector<vector<long long>> splitPainting(vector<vector<int>> &segments)
    {
        vector<long long> line1(100001, 0), line2(100001, 0);
        int maxVal = -1, minVal = INT_MAX;

        for (auto x : segments)
        {
            line1[x[0]] += x[2];
            line2[x[1]] -= x[2];
            minVal = min(minVal, x[0]);
            maxVal = max(maxVal, x[1]);
        }

        vector<vector<long long>> res;
        long long sum = line1[minVal] + line2[minVal];
        int prev = minVal;

        for (int i = minVal + 1; i <= maxVal; i++)
        {
            if (line1[i] == 0 && line2[i] == 0)
                continue;

            if (sum != 0)
                res.push_back({prev, i, sum});
            sum += (line1[i] + line2[i]);
            prev = i;
        }

        return res;
    }
};