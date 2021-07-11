// Solution:-

class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &e)
    {
        int n = maze.size(), m = maze[0].size();
        queue<vector<int>> q;
        if (e[0] != 0 && maze[e[0] - 1][e[1]] == '.')
        {
            q.push({e[0] - 1, e[1]});
            maze[e[0]][e[1]] = '+';
        }
        if (e[1] != 0 && maze[e[0]][e[1] - 1] == '.')
        {
            q.push({e[0], e[1] - 1});
            maze[e[0]][e[1]] = '+';
        }

        if (e[0] != n - 1 && maze[e[0] + 1][e[1]] == '.')
        {
            q.push({e[0] + 1, e[1]});
            maze[e[0]][e[1]] = '+';
        }
        if (e[1] != m - 1 && maze[e[0]][e[1] + 1] == '.')
        {
            q.push({e[0], e[1] + 1});
            maze[e[0]][e[1]] = '+';
        }

        maze[e[0]][e[1]] = '+';
        int res = 1;

        while (!q.empty())
        {

            int k = q.size();
            for (int i = 0; i < k; i++)
            {
                int x = q.front()[0], y = q.front()[1];
                q.pop();

                if (x == 0 || y == 0 || x == (n - 1) || y == (m - 1))
                    return res;

                if (x - 1 >= 0 && maze[x - 1][y] == '.')
                {
                    q.push({x - 1, y});
                    maze[x - 1][y] = '+';
                }
                if (x + 1 < n && maze[x + 1][y] == '.')
                {
                    q.push({x + 1, y});
                    maze[x + 1][y] = '+';
                }
                if (y - 1 >= 0 && maze[x][y - 1] == '.')
                {
                    q.push({x, y - 1});
                    maze[x][y - 1] = '+';
                }
                if (y + 1 < m && maze[x][y + 1] == '.')
                {
                    q.push({x, y + 1});
                    maze[x][y + 1] = '+';
                }
            }

            res++;
        }

        return -1;
    }
};