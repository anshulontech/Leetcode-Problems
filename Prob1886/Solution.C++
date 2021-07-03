// Link To Problem:-
// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/

// METHOD 1:-

class Solution
{
public:
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        int n = mat.size();
        vector<bool> a(4, true);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] != target[j][n - 1 - i])
                    a[0] = false;
                if (mat[i][j] != target[n - 1 - i][n - 1 - j])
                    a[1] = false;
                if (mat[i][j] != target[n - 1 - j][i])
                    a[2] = false;
                if (mat[i][j] != target[i][j])
                    a[3] = false;
            }

        for (auto x : a)
            if (x)
                return x;

        return false;
    }
};