// https://leetcode.com/problems/rotate-image/

// Time Complexity:-O(N^N). where N is total number of rows in matrix.
// Space Complexity:-O(1).
    
// Approach:-
//     After carefull observation it can be concluded that rotation of a matrix by 90 towards right can be achived by 
// getting transpose of matrix and than reversing the rows.
    
//     So here we are going to do is to first get the transpose of matrix and than using reverse function we are going 
// to freverse each row.


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N=matrix.size();
        for(int i=0;i<N;i++)
            for(int j=i+1;j<N;j++)
                swap(matrix[i][j],matrix[j][i]);
        
        for(int i=0;i<N;i++)
            reverse(matrix[i].begin(),matrix[i].end());
    }
};



class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int N = matrix.size(), a = 0, b = N - 1;

        while (a < b)
        {
            for (int i = 0; i < (b - a); i++)
            {
                swap(matrix[a][a + i], matrix[a + i][b]);
                swap(matrix[a][a + i], matrix[b][b - i]);
                swap(matrix[a][a + i], matrix[b - i][a]);
            }

            a++;
            b--;
        }
    }
};