// Solution:-

class Solution
{
public:
    int kthLargestValue(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size(), m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m));

        priority_queue<int, vector<int>, greater<int>> pq;

        dp[0][0] = matrix[0][0];
        pq.push(dp[0][0]);

        for (int i = 1; i < m; i++)
        {
            int val = dp[0][i - 1] ^ matrix[0][i];
            dp[0][i] = val;
            if (pq.size() < k)
                pq.push(val);
            else if (pq.top() < val)
            {
                pq.pop();
                pq.push(val);
            }
        }
        for (int i = 1; i < n; i++)
        {
            int val = dp[i - 1][0] ^ matrix[i][0];
            dp[i][0] = val;
            if (pq.size() < k)
                pq.push(val);
            else if (pq.top() < val)
            {
                pq.pop();
                pq.push(val);
            }
        }

        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
            {
                int val = dp[i - 1][j] ^ dp[i][j - 1] ^ dp[i - 1][j - 1] ^ matrix[i][j];
                dp[i][j] = val;
                if (pq.size() < k)
                    pq.push(val);
                else if (pq.top() < val)
                {
                    pq.pop();
                    pq.push(val);
                }
            }

        return pq.top();
    }
};