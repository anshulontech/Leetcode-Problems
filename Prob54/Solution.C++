// Link To Problem:-
// https://leetcode.com/problems/spiral-matrix/

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> store;
        if (matrix.size() == 0)
            return store;
        int m = matrix.size(), n = matrix[0].size();
        int num = m * n;

        int row = 0, col = 0, i = 0, j = 0;

        while (num)
        {
            i = row;
            j = col;

            while (num && j < (n - col))
            { // traversing the row in forward order.
                store.push_back(matrix[i][j++]);
                num--;
            }

            j--;
            i++;

            while (num && i < (m - row))
            { // traversing the last col in top-down order.
                store.push_back(matrix[i++][j]);
                num--;
            }

            i--;
            j--;

            while (num && j >= col)
            { // traversing the last column in reverse order.
                store.push_back(matrix[i][j--]);
                num--;
            }

            j++;
            i--;

            while (num && i > row)
            { // traversing the first col in down-top order.
                store.push_back(matrix[i--][j]);
                num--;
            }

            row++; // Increasing them to reduce the matrix by removing first and last row of current matrix
            col++; // Increasing them to reduce the matrix by removing first and last column of current matrix
        }
        return store;
    }
};