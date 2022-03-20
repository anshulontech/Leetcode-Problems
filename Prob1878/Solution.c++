// Link To The Problem:-
// https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/

// Solution:-

class Solution
{
public:
    vector<int> getBiggestThree(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> sum1(n, vector<int>(m, 0)), sum2(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            sum1[i][0] = grid[i][0];
            sum2[i][0] = grid[i][0];
        }

        for (int i = 1; i < m; i++)
        {
            sum1[0][i] = grid[0][i];
            sum2[n - 1][i] = grid[n - 1][0];
        }

        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                sum1[i][j] = grid[i][j] + sum1[i - 1][j - 1];

        for (int i = n - 2; i >= 0; i--)
            for (int j = 1; j < m; j++)
                sum2[i][j] = grid[i][j] + sum2[i + 1][j - 1];

        priority_queue<int> pq;

        set<int> visited;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                int k = 1;

                if (visited.find(grid[i][j]) == visited.end())
                {
                    pq.push(grid[i][j]);
                    visited.insert(grid[i][j]);
                }

                while (k)
                {
                    int currSum = 0;

                    if (i - k >= 0 && j + k < m)
                    {
                        currSum += (sum2[i - k][j + k] - sum2[i][j] + grid[i][j]);
                    }
                    else
                        break;

                    if (i + k < n && j + k < m)
                    {
                        currSum += (sum1[i + k][j + k] - sum1[i][j]);
                    }
                    else
                        break;

                    if (j + k * 2 < m)
                    {
                        currSum += (sum2[i][j + 2 * k] - sum2[i + k][j + k]);
                        currSum += (sum1[i][j + 2 * k] - sum1[i - k][j + k]);
                        currSum -= grid[i][j + 2 * k];
                    }
                    else
                        break;

                    if (visited.find(currSum) == visited.end())
                    {
                        visited.insert(currSum);
                        pq.push(currSum);
                    }

                    k++;
                }
            }

        vector<int> res;

        for (int i = 0; i < 3 && !pq.empty(); i++)
        {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
};