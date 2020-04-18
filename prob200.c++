// https://leetcode.com/problems/number-of-islands/

// Time coplexity:-O(N^2).
// Space Complexity:-O(1).
    
// Approach:-
//     Initially we will make a variable named count whiah is used to store the number of island in the grid. On itterating the 
// grid if we will get encountred with '1' than it represents a island hence we will increase the value of count by 1 and call 
// a function named remove_island which is used to ake that 1 to 0 and all nearby 1 also as they all are also the part of the 
// that island. In thi loop again using backtrackig we will remove all other neraby 1 to 0 and hence by this all are converted 
// into a part of water and will not be counted any more. I the last we will return the value of count which denotes the number 
// of island in the grid.

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j]=='1')
                {
                    count++;
                    remove_island(grid,i,j);
                }
        return count;
    }
    
    void remove_island(vector<vector<char>>& grid,int i,int j)
    {
        grid[i][j]='0';
        
        if(i>0&&grid[i-1][j]=='1')
            remove_island(grid,i-1,j);
        if(j>0&&grid[i][j-1]=='1')
            remove_island(grid,i,j-1);
        if(i<grid.size()-1&&grid[i+1][j]=='1')
            remove_island(grid,i+1,j);
        if(j<grid[i].size()-1&&grid[i][j+1]=='1')
            remove_island(grid,i,j+1);
            
    }
};