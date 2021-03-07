// Solution:-

class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0));
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (isWater[i][j] == 1)
                {
                    q.push({i, j});
                    visited[i][j] = true;
                }

        int k = 0;

        while (!q.empty())
        {
            int z = q.size();

            for (int i = 0; i < z; i++)
            {
                pair<int, int> pq = q.front();
                q.pop();

                int x = pq.first, y = pq.second;

                res[x][y] = k;

                if (x - 1 >= 0 && visited[x - 1][y] == false)
                {
                    q.push({x - 1, y});
                    visited[x - 1][y] = true;
                }
                if (x + 1 < n && visited[x + 1][y] == false)
                {
                    q.push({x + 1, y});
                    visited[x + 1][y] = true;
                }
                if (y - 1 >= 0 && visited[x][y - 1] == false)
                {
                    q.push({x, y - 1});
                    visited[x][y - 1] = true;
                }
                if (y + 1 < m && visited[x][y + 1] == false)
                {
                    q.push({x, y + 1});
                    visited[x][y + 1] = true;
                }
            }

            k++;
        }

        return res;
    }
};