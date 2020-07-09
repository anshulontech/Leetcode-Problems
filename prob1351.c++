// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/

// Time Complextiy:-O(M+N).
// Space Complextiy:-O(1).

// Approach:-
//     In this we are starting from the top right most corner and if the element there is negative than all the elements 
// below to this are also negative hence we will add the number fo elements below to this including this one to the result 
// and move left as we had already counted below elements , but if the current element is not negative than negative 
// number is found only in the down side not left side so we will take one step down and check there , So by this we 
// itterate the matrix only M+N times .

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int N=grid.size();
        
        int i=0,j=grid[0].size()-1;
        int res=0;
        
        while(i<N && j>=0)
            if(grid[i][j]<0) {
                res+=N-i;
                j--;
            }
            else
                i++;
        
        
        return res;
    }
};

// Time Complextiy: -O(N *log(M)).
// Space Complextiy:- O(1).

// Approach:-
//     We will apply binary search in each row and found the upper bound of 0 and than add the number fo items left after
// this to result.

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int res = 0;
        int N = grid.size();
        int M = grid[0].size();

        for (int i = 0; i < N; i++)
        {
            int index = search(grid[i], 0);
            res += M - index;
        }

        return res;
    }

    int search(vector<int> &arr, int target)
    {
        int start = 0, end = arr.size() - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (arr[mid] >= target)
                start = mid + 1;
            else
                end = mid - 1;
        }

        return start;
    }
};