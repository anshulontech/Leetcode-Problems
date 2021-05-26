// Link To Problem:-
// https://leetcode.com/problems/search-a-2d-matrix/

class Solution
{
private:
    int n, m;

public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        n = matrix.size();
        m = n > 0 ? matrix[0].size() : 0;

        if (n == 0 || m == 0)
            return false;

        int row = searchCol(matrix, target);
        if (row >= n || row < 0)
            return false;

        return findTarget(matrix, row, target);
    }

    int searchCol(vector<vector<int>> &matrix, int &target)
    {
        int start = 0, end = n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (matrix[mid][m - 1] == target)
                return mid;
            if (matrix[mid][m - 1] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }

        return start;
    }

    bool findTarget(vector<vector<int>> &matrix, int &row, int &target)
    {
        int start = 0, end = m - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (matrix[row][mid] == target)
                return true;
            else if (matrix[row][mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }

        return false;
    }
};

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();

        int m = n ? matrix[0].size() : 0;

        int i = 0, j = m - 1;

        while (i < n && j >= 0)
        {
            if (matrix[i][j] == target)
                return true;
            if (matrix[i][j] > target)
                j--;
            else
                i++;
        }

        return false;
    }
};

// Similar Approach As that of above one.

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();

        int m = n ? matrix[0].size() : 0;

        int i = 0, j = m - 1;

        if (m == 0 || n == 0)
            return false;

        while (i < n && matrix[i][j] < target)
            i++;

        if (i < n)
            while (j >= 0 && matrix[i][j] > target)
                j--;

        if (i < n && j >= 0 && matrix[i][j] == target)
            return true;
        else
            return false;
    }
};