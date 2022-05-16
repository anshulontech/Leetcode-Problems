// Link To The Problem:-
//  https://leetcode.com/problems/spiral-matrix/

// Solution:-

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;

        int n = matrix.size(), m = matrix[0].size();
        int count = m * n;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < m - i && count > 0; j++, count--)
                res.push_back(matrix[i][j]);

            for (int k = i + 1; k < n - i && count > 0; k++, count--)
                res.push_back(matrix[k][m - i - 1]);

            for (int j = m - 1 - i - 1; j >= i && count > 0; j--, count--)
                res.push_back(matrix[n - i - 1][j]);

            for (int k = n - i - 2; k > i && count > 0; k--, count--)
                res.push_back(matrix[k][i]);
        }

        return res;
    }
};