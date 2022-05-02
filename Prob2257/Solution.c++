// Link To The Problem:-
// https://leetcode.com/problems/count-unguarded-cells-in-the-grid/

// Solution:-

class Solution
{
public:
    int countUnguarded(int n, int m, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {
        int res = 0;

        vector<vector<int>> mat(n, vector<int>(m, 0));

        for (auto x : guards)
            mat[x[0]][x[1]] = 1;

        for (auto x : walls)
            mat[x[0]][x[1]] = 2;

        res += guards.size() + walls.size();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (mat[i][j] == 1)
                {
                    int x = i + 1;

                    while (x < n && mat[x][j] != 1 && mat[x][j] != 2)
                    {
                        if (mat[x][j] == 0)
                        {
                            mat[x][j] = -1;
                            res++;
                        }

                        x++;
                    }

                    x = i - 1;

                    while (x >= 0 && mat[x][j] != 1 && mat[x][j] != 2)
                    {
                        if (mat[x][j] == 0)
                        {
                            mat[x][j] = -1;
                            res++;
                        }

                        x--;
                    }

                    int y = j + 1;

                    while (y < m && mat[i][y] != 1 && mat[i][y] != 2)
                    {
                        if (mat[i][y] == 0)
                        {
                            mat[i][y] = -1;
                            res++;
                        }

                        y++;
                    }

                    y = j - 1;

                    while (y >= 0 && mat[i][y] != 1 && mat[i][y] != 2)
                    {
                        if (mat[i][y] == 0)
                        {
                            mat[i][y] = -1;
                            res++;
                        }

                        y--;
                    }
                }

        return m * n - res;
    }
};