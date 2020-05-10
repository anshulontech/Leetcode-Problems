// https://leetcode.com/problems/number-of-closed-islands/

// Time Complexity:-O(N^2).
// Space Complexity:-O(1).
    
// Approach:-
//     In this what we are going to do is that if we will encounter with a zero than we will start for search near to it 
//that is it has land or not. Our search will work till we will not encounter a visited land or water or the boundary. If 
//we will encounter with the boundary and it has land as a part than it will not be considered as answer hence it will be 
//terminated using flag variable else if land is not present at oeriferi than it will be considered.

class Solution {
private:
    int closed_islands=0;
    int flag;
public:
    int closedIsland(vector<vector<int>>& grid) {
        for(int i=1;i<grid.size()-1;i++)
            for(int j=1;j<grid[i].size()-1;j++)
                if(grid[i][j]==0)
                {
                    flag=0;
                    grid[i][j]=-1;
                    checkisland(grid,i-1,j);
                    checkisland(grid,i+1,j);
                    checkisland(grid,i,j-1);
                    checkisland(grid,i,j+1);
                    if(flag==0)
                        closed_islands++;
                }
        
        return closed_islands;
    }
    
    void checkisland(vector<vector<int>> & grid,int i,int j)
    {
        if(i<0 || i==grid.size() || j<0 || j==grid[i].size() || grid[i][j]==-1 || grid[i][j]==1)
            return ;
        
        if(grid[i][j]==0 &&(i==0 || i==grid.size()-1 || j==0 || j==grid[i].size()-1))
        {
            flag=1;
            return;
        }
        
        grid[i][j]=-1;
        checkisland(grid,i-1,j);
        checkisland(grid,i+1,j);
        checkisland(grid,i,j-1);
        checkisland(grid,i,j+1);
        
        return ;
        
    }
};