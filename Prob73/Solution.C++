// Link To Problem:-
// https://leetcode.com/problems/set-matrix-zeroes/

// METHOD 1:-

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        unordered_set<int> row;
        unordered_set<int> col;

        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
                if (matrix[i][j] == 0)
                    row.insert(i), col.insert(j);

        for (auto x : row)
            for (int j = 0; j < matrix[x].size(); j++)
                matrix[x][j] = 0;

        for (auto x : col)
            for (int i = 0; i < matrix.size(); i++)
                matrix[i][x] = 0;
    }
};

// METHOD 2:-

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0)
            return;
        bool isCol = false;
        int R = matrix.size();
        int C = matrix[0].size();

        for (int i = 0; i < R; i++)
        {
            if (matrix[i][0] == 0)
                isCol = true;

            for (int j = 1; j < C; j++)
                if (matrix[i][j] == 0)
                    matrix[i][0] = 0, matrix[0][j] = 0;
        }

        for (int i = 1; i < R; i++)
            if (matrix[i][0] == 0)
                for (int j = 0; j < C; j++)
                    matrix[i][j] = 0;

        for (int j = 1; j < C; j++)
            if (matrix[0][j] == 0)
                for (int i = 0; i < R; i++)
                    matrix[i][j] = 0;

        if (matrix[0][0] == 0)
            for (int j = 0; j < C; j++)
                matrix[0][j] = 0;

        if (isCol)
            for (int i = 0; i < R; i++)
                matrix[i][0] = 0;
    }
};