// Solution:-

class Solution
{
public:
    vector<bool> canEat(vector<int> &candiesCount, vector<vector<int>> &queries)
    {
        int n = candiesCount.size();

        vector<int> sum(n + 1, 0);

        for (int i = 1; i < n + 1; i++)
            sum[i] = sum[i - 1] + candiesCount[i - 1];

        vector<bool> res;
        int k = queries.size();

        for (int i = 0; i < k; i++)
        {
            int val = sum[queries[i][0]];
            int k = 0;
            while (val > 0 && k < queries[i][1])
            {
                val -= queries[i][2];
                k++;
            }

            if (val <= 0 && sum[queries[i][0] + 1] + 1 >= queries[i][1])
                res.push_back(true);
            else
                res.push_back(false);
        }

        return res;
    }
};