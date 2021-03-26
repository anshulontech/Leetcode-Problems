// Solution:-

class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &c, int s)
    {
        priority_queue<pair<double, int>> pq;
        int n = c.size();
        for (int i = 0; i < n; i++)
        {
            double long gain = (double)(c[i][0] + 1) / (double)(c[i][1] + 1) - (double)(c[i][0]) / (double)(c[i][1]);

            pq.push({gain, i});
        }

        while (s--)
        {
            auto x = pq.top();
            pq.pop();

            int idx = x.second;

            c[idx][0]++;
            c[idx][1]++;

            long double gain = (double)(c[idx][0] + 1) / (double)(c[idx][1] + 1) - (double)(c[idx][0]) / (double)(c[idx][1]);

            pq.push({gain, idx});
        }

        long double res = 0;

        for (auto x : c)
            res += (double)(x[0]) / (double)(x[1]);

        res /= n;

        return res;
    }
};