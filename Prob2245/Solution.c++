// Link To The Problem:-
// https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path/

// Solution:-

class Solution
{
public:
    int maxTrailingZeros(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();

        vector<vector<pair<int, int>>> count(n, vector<pair<int, int>>(m + 1)), hor(n, vector<pair<int, int>>(m + 1));

        for (int i = 0; i < n; i++)
            for (int j = m - 1; j >= 0; j--)
            {
                while (grid[i][j] % 2 == 0)
                {
                    count[i][j].first++;
                    grid[i][j] /= 2;
                }

                while (grid[i][j] % 5 == 0)
                {
                    count[i][j].second++;
                    grid[i][j] /= 5;
                }

                hor[i][j].first = count[i][j].first + hor[i][j + 1].first;
                hor[i][j].second = count[i][j].second + hor[i][j + 1].second;
            }

        int res = 0;

        for (int j = 0; j < m; j++)
        {
            int count1 = 0, count2 = 0;

            for (int i = 0; i < n; i++)
            {
                count1 += count[i][j].first;
                count2 += count[i][j].second;

                res = max(res, min(count1, count2));
                res = max(res, min(count1 + hor[i][j + 1].first, count2 + hor[i][j + 1].second));
                res = max(res, min(count1 + hor[i][0].first - hor[i][j].first, count2 + hor[i][0].second - hor[i][j].second));
            }

            count1 = 0, count2 = 0;

            for (int i = n - 1; i >= 0; i--)
            {
                count1 += count[i][j].first;
                count2 += count[i][j].second;

                res = max(res, min(count1, count2));

                res = max(res, min(count1 + hor[i][j + 1].first, count2 + hor[i][j + 1].second));
                res = max(res, min(count1 + hor[i][0].first - hor[i][j].first, count2 + hor[i][0].second - hor[i][j].second));
            }
        }
        return res;
    }
};