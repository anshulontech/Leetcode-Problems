// Solution:-

class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {
        int n = rowSum.size(), m = colSum.size();

        vector<vector<int>> res(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (rowSum[i] == 0 || colSum[j] == 0)
                {
                    res[i][j] = 0;
                    continue;
                }

                int temp = min(rowSum[i], colSum[j]);
                res[i][j] = temp;
                rowSum[i] -= temp;
                colSum[j] -= temp;
            }

        return res;
    }
};