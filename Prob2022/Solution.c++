// Link To Problem:-
// https://leetcode.com/problems/convert-1d-array-into-2d-array/

// Solution:-

class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &A, int m, int n)
    {
        int len = A.size();
        if (m * n != len)
            return {};
        vector<vector<int>> res(m, vector<int>(n));
        int k = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                res[i][j] = A[k++];

        return res;
    }
};