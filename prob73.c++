// https://leetcode.com/problems/set-matrix-zeroes/

// Time Complexity:-O(M*N).
// Space Complexity:-O(N+M).
    
// Approach:-
//     In this approach what we are going to do is that we will store the rows and columns in different sets of poisition 
// whose value is equal to 0. now we will traverse the row map and than make all elements in store row to zero and than 
// do same for the col set.

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

// Time Complexity:-O(M*N).
// Space Complexity:-O(1).

// Approach:-
//     In this approach what we are going to do is that if we will encounter with any 0 than we will make it's row and
// col first element to be 0 . Now by doing this we traverse the whole matrix . Now we will start to traverse the 1st 
// row and 1col of matrix and if on moving along col if we will find any 0 than we will make it's entire col to 0 and 
// similarely for row , we will make corresponding to 0. This saves our extra space of O(N+M). Here we have done some 
// optimisation for isCol to check wheather we will make 1st col to 0 or not and the code is easy to explain.

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