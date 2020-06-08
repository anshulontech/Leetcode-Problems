// https://leetcode.com/problems/pacific-atlantic-water-flow/

// Time Complexity:-O(M*N).
// Space Complexity:-O(M*N).
    
// Approach:-
//     In this what we are going to do is that we are making two different matrix which are used to mark those index 
// from ehich we can go to the pacific and atlantic oceans differently that is pacific ocean matrix used to store the 
// index from which we can go to pacific ocean and the atlantic one was for atlantic . Now we will traverse both the 
// matrix and those indexes having value 1 in both the matrix will fall into the category of result.
        
// How does dfs works?
//     Dfs will work with the scheme that we will check for the boundary index that in which direction move so that 
// the value is higher or equal as on traversing from them the value of their height will be greatr or equal hence we 
// will go fro their to the respective ocean .

class Solution
{
private:
    int m, n;

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
    {

        vector<vector<int>> res;

        if (matrix.size() == 0)
            return res;
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>> pacific(m, vector<int>(n));
        vector<vector<int>> atlantic(m, vector<int>(n));

        for (int i = 0; i < m; i++)
        {
            dfs(matrix, i, 0, INT_MIN, pacific);
            dfs(matrix, i, n - 1, INT_MIN, atlantic);
        }
        for (int i = 0; i < n; i++)
        {
            dfs(matrix, 0, i, INT_MIN, pacific);
            dfs(matrix, m - 1, i, INT_MIN, atlantic);
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (pacific[i][j] == 1 && atlantic[i][j] == 1)
                    res.push_back({i, j});

        return res;
    }

    void dfs(vector<vector<int>> &matrix, int row, int col, int preVal, vector<vector<int>> &ocean)
    {
        if (ocean[row][col] == 1 || matrix[row][col] < preVal)
            return;

        ocean[row][col] = 1;

        if (row > 0)
            dfs(matrix, row - 1, col, matrix[row][col], ocean);
        if (col > 0)
            dfs(matrix, row, col - 1, matrix[row][col], ocean);
        if (row < m - 1)
            dfs(matrix, row + 1, col, matrix[row][col], ocean);
        if (col < n - 1)
            dfs(matrix, row, col + 1, matrix[row][col], ocean);
    }
};