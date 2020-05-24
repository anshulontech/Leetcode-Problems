// https://leetcode.com/problems/search-a-2d-matrix-ii/

// Time Complexity:- O(N+M).
// Space Complexity:-O(1).
    
// Approach:-
//     In this what we are going to do is that we will satrt our search from the top right corner. If we found the 
// value than we will return true else if target is greater tha current than we will search for next row else search 
// for previous column and so on till till we exit the matrix. If we exit the matrix than we will return false.


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0)
            return false;
        int j=matrix[0].size()-1,i=0;
        
        while(j>=0 && i<matrix.size())
            if(matrix[i][j]==target)
                return true;
            else
                if(matrix[i][j]<target)
                    i++;
                else
                    j--;
        
        return false;
    }
};