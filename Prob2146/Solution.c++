// Link To Problem:-
// https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range/

// Solution:-

class Solution
{
private:
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        if (a[0] < b[0])
            return true;
        if (a[0] > b[0])
            return false;

        if (a[1] < b[1])
            return true;
        if (a[1] > b[1])
            return false;

        if (a[2] < b[2])
            return true;
        return false;
    }

public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>> &grid, vector<int> &pricing, vector<int> &start, int k)
    {
        vector<vector<int>> result;

        int n = grid.size(), m = grid[0].size();

        queue<vector<int>> q;
        q.push({start[0], start[1], grid[start[0]][start[1]]});

        if (grid[start[0]][start[1]] >= pricing[0] && grid[start[0]][start[1]] <= pricing[1])
        {
            result.push_back(start);
            k--;
        }

        grid[start[0]][start[1]] = -1;

        while (k > 0 && !q.empty())
        {
            int len = q.size();

            vector<vector<int>> temp;

            for (int i = 0; i < len; i++)
            {
                int x = q.front()[0], y = q.front()[1];
                q.pop();

                if (x - 1 >= 0 && grid[x - 1][y] > 0)
                {
                    q.push({x - 1, y, grid[x - 1][y]});
                    if (grid[x - 1][y] >= pricing[0] && grid[x - 1][y] <= pricing[1])
                        temp.push_back({grid[x - 1][y], x - 1, y});

                    grid[x - 1][y] = -1;
                }

                if (y - 1 >= 0 && grid[x][y - 1] > 0)
                {
                    q.push({x, y - 1, grid[x][y - 1]});
                    if (grid[x][y - 1] >= pricing[0] && grid[x][y - 1] <= pricing[1])
                        temp.push_back({grid[x][y - 1], x, y - 1});

                    grid[x][y - 1] = -1;
                }

                if (x + 1 < n && grid[x + 1][y] > 0)
                {
                    q.push({x + 1, y, grid[x + 1][y]});
                    if (grid[x + 1][y] >= pricing[0] && grid[x + 1][y] <= pricing[1])
                        temp.push_back({grid[x + 1][y], x + 1, y});

                    grid[x + 1][y] = -1;
                }

                if (y + 1 < m && grid[x][y + 1] > 0)
                {
                    q.push({x, y + 1, grid[x][y + 1]});
                    if (grid[x][y + 1] >= pricing[0] && grid[x][y + 1] <= pricing[1])
                        temp.push_back({grid[x][y + 1], x, y + 1});

                    grid[x][y + 1] = -1;
                }
            }

            sort(temp.begin(), temp.end(), cmp);

            for (auto x : temp)
            {
                if (k == 0)
                    break;

                result.push_back({x[1], x[2]});
                k--;
            }
        }

        return result;
    }
};