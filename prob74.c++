// https://leetcode.com/problems/search-a-2d-matrix/

// Time Complexity:-O(log(N)+log(M)).
// Space Complexity:-O(1).
    
// Approach:-
//     First we will found the upper bound of the target in the last column of the matrix using binary search with 
// user defined function searchCol and after this we will execute binary search in that row for target and if we 
// found the target than we will return true in that case else will return false.

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

// Time Complexity:-O(M+N).
// Space Complexity:-O(1).
    
// Approach:-
//     In this approach we will start from the top right corner of the matrix and if the current element is greater 
// than the target than it will be definately in the left part so we will move leftward else if it is greater than 
// target than we will move as it will definately be in the downward direction . If we found the element than we will 
// return true else in searching if we reach out of the matrix we will return false. 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        
        int m= n ? matrix[0].size() : 0 ;
        
        int i=0,j=m-1;
        
        while(i<n && j>=0) {
            if(matrix[i][j]==target)
                return true;
            if(matrix[i][j]>target)
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