// Link To The Problem:-
//  https://leetcode.com/problems/rotate-image/

// Solution:-

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        for (int i = 0; i < n / 2; i++)
        {
            for (int k = i; k < n - i - 1; k++)
            {
                swap(matrix[i][k], matrix[k][n - 1 - i]);
                swap(matrix[n - 1 - k][i], matrix[n - 1 - i][n - 1 - k]);
                swap(matrix[i][k], matrix[n - 1 - i][n - 1 - k]);
            }
        }
    }
};
