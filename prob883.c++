// https://leetcode.com/problems/projection-area-of-3d-shapes/submissions/

// Time Complexity:-O(3*N).
// Space Complexity:-O(1).
    
// Approach:-
//     Using 3 variables named xy,yz,zx we are going to calculate the projection area from te sides as the name suggests.Now 
// for the yz side we will check the max value in grid[i] as this is only visible from that side and counted and do for whole 
// set and store he value in yz. For xy we count number of poisitions having value 0 or less than zero as on view from top these 
// will not be visible and set this to to xy. Similar opration can be done for zx as that of yz but here max value is found 
// between grid[][j]. After getting all these we will return the sum of these values as final answer.

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        if(grid.size()==0)
            return 0;
        int zero=0;
        int xy=0,yz=0,zx=0;
        
        for(int i=0;i<grid.size();i++)
        {
            int count=INT_MIN;
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]>count)
                    count=grid[i][j];
                if(grid[i][j]<=0)
                    zero++;
            }
            
            yz+=count;
        }
        
        xy=grid.size()*grid[0].size()-zero;
        
        for(int j=0;j<grid[0].size();j++)
        {
            int count=INT_MIN;
            for(int i=0;i<grid.size();i++)
                if(grid[i][j]>count)
                    count=grid[i][j];
            
            zx+=count;
        }
        
        return xy+yz+zx;
            
    }
};