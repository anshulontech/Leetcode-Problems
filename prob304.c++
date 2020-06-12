// https://leetcode.com/problems/range-sum-query-2d-immutable/

// Time Complexity:-O(N^2). For Maintaing matrix and O(1) for calculating sum
// Space Complexity:-O(N^2).
    
// Approach:-
//     We will use a dp table for storing the sum of all the elements starting from the (0,0) index to that index which 
// uses O(N^2) time. Now to calculate the sum between two index we will use this dp table for help so that the time 
// complexity will become O(1). For calculating sum we have sumRegion function whose code is clear and easy to understand 
// which tells we will first take sum of whole rectangle till row2,col2 index and than substract the sum for neighbouring 
// rectangle to the upper and left border, but as substracting the upper and left rectangle individually we had substracted 
// the left upper twice hence we have to add it one time more.

class NumMatrix
{
private:
    int row, col;
    vector<vector<int>> dp;

public:
    NumMatrix(vector<vector<int>> &matrix)
    {

        row = matrix.size();

        col = row > 0 ? matrix[0].size() : 0;
        dp = vector<vector<int>>(row + 1, vector<int>(col + 1, 0));

        for (int i = 1; i < row + 1; i++)
            for (int j = 1; j < col + 1; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
    }
};