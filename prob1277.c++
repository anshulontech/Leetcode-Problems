// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

// Time Complexity:-O(m*n).
// Space Complexity:-O(1).
    
// Approach:-
//     In this we will itterate the matrix and on encountr with 1 we will check for the neighbours. The value of 
// neighbour cell represents the side of max square that that they will be a part so we will take the min from them 
// and add to res with + as now the i,j cell is also a part of the square. So by doing this we are going to itterate 
// the matrix and obtain our answer.

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int res = 0;
        for (int i = 0; i < matrix.size(); i++)
            if (matrix[i][0] == 1)
                res++;

        for (int j = 1; j < matrix[0].size(); j++)
            if (matrix[0][j] == 1)
                res++;

        for (int i = 1; i < matrix.size(); i++)
            for (int j = 1; j < matrix[i].size(); j++)
                if (matrix[i][j] == 1)
                    if (matrix[i - 1][j] != 0 && matrix[i][j - 1] != 0 && matrix[i - 1][j - 1] != 0)
                    {
                        int val = min(matrix[i - 1][j], matrix[i][j - 1]);
                        val = min(val, matrix[i - 1][j - 1]);

                        matrix[i][j] = val + 1;
                        res += (val + 1);
                    }
                    else
                        res++;

        return res;
    }
};