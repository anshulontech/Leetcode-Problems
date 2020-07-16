// https://leetcode.com/problems/spiral-matrix-ii/description/

// Time Complexity:-O(n*n).
// Space Complexity:-O(n*n). To store the result.

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> store(n, vector<int>(n));

        int k = n * n;
        int x = 1;

        int row = 0, col = 0;

        while (k > 0)
        {
            for (int i = col; i < n - col && k > 0; i++)
            {
                store[row][i] = x++;
                k--;
            }

            for (int i = row + 1; i < n - row && k > 0; i++)
            {
                store[i][n - col - 1] = x++;
                k--;
            }

            for (int i = n - col - 2; i >= col && k > 0; i--)
            {
                store[n - row - 1][i] = x++;
                k--;
            }

            for (int i = n - row - 2; i > row && k > 0; i--)
            {
                store[i][col] = x++;
                k--;
            }

            row++;
            col++;
        }

        return store;
    }
};