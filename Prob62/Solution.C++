// Link To Problem:-
// https://leetcode.com/problems/unique-paths/

class Solution
{
public:
    int uniquePaths(int m, int n)
    {

        vector<vector<int>> store(n, vector<int>(m));

        for (int i = 0; i < n; i++)
            store[i][m - 1] = 1;

        for (int j = 0; j < m; j++)
            store[n - 1][j] = 1;

        for (int i = n - 2; i >= 0; i--)
            for (int j = m - 2; j >= 0; j--)
                store[i][j] = store[i + 1][j] + store[i][j + 1];

        return store[0][0];
    }
};