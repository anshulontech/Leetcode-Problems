// https://leetcode.com/problems/minimum-path-sum/submissions/

// Time Complexity:-O(x+y).
// Space Complexity:-O(x).

// METHOD 1:-FIRST MOVE VERTICALLY.

// Approach:-
// Initially we will make a vector named store of size x and assign all value equal to grid[0][0].Now we will updating the 
// vector store with idea that how the values change when we will move down to that column . After this group we will start
// a new loop which initially represents the 2nd column and than update the vector store with idea that how values changes
// to minimum value if we will move from left or from upwards. at the last we return store[x-1] which represents the last 
// value of the grid after we update it. 


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int x=grid.size();
        int y=grid[0].size();
        vector<int> store(x,grid[0][0]);
        for(int i=1;i<x;i++)
            store[i]=store[i-1]+grid[i][0];  // Upadting the store by cheking how values change if we will move vertically.
        
        for(int j=1;j<y;j++)
        {
            store[0]+=grid[0][j];
            for(int i=1;i<x;i++)
                store[i]=min(store[i-1],store[i])+grid[i][j];  //updating the values by checking minimum change on movement either from up or from left.
        }
        
        return store[x-1]; // returning the value which represents the last grid on mimimum change.
    }
};

// METHOD 2:-FIRST MOVE HORIZONTALLY.

// Approach:-
// Same as that of above one but the change is that we will first move horizontally not vertically.


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int x=grid.size();
        int y=grid[0].size();
        vector<int> store(y,grid[0][0]);
        for(int i=1;i<y;i++)
            store[i]=store[i-1]+grid[0][i]; // Upadting the store by cheking how values change if we will move horizontally.
        
        for(int i=1;i<x;i++)
        {
            store[0]+=grid[i][0];
            for(int j=1;j<y;j++)
                store[j]=min(store[j-1],store[j])+grid[i][j];     //updating the values by checking minimum change on movement either from up or from left.
        }
        
        return store[y-1];  // returning the value which represents the last grid on mimimum change.
    }
};