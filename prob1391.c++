// https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/

// Time Complexity:-O(m*n).
// Space Complexity:-O(1).
    
// Approach:-
//     In thi what we are doing is that we will start from the top left corner and go as our path will take to us. If 
// the end point of path represents the bottom right poisition than we will return true else return false.
        
// How To move in path:-
//     We will set a map which will tell us the directions in which we can move. Now let we are at some poisition and 
// we will found that we have to go down than we will go for the next row and same column and check that is entry point 
// pointing to come from top or not , if it is than we will go to next one following the route and ove forward untill 
// false condition or last one will not occur but if it was not than we will return false in that condition.

class Solution {
private:
    unordered_map<int,pair<int,int>> dire;
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        dire.insert(make_pair(1,make_pair(-1,1)));
        dire.insert(make_pair(2,make_pair(2,-2)));
        dire.insert(make_pair(3,make_pair(-1,-2)));
        dire.insert(make_pair(4,make_pair(-2,1)));
        dire.insert(make_pair(5,make_pair(-1,2)));
        dire.insert(make_pair(6,make_pair(2,1)));
        
        int start=dire[grid[0][0]].first;
        int end=dire[grid[0][0]].second;
        
        bool ans;
        
        if(end==-2)
            ans= checkpath(grid,-end,1,0);
        else
            if(end==1)
                ans= checkpath(grid,-end,0,1);
            else
                if(grid.size()==1 && grid[0].size()==1)
                    ans= true;
                else
                    ans= false;
        if(!ans)
        {
            if(start==-2)
                ans= checkpath(grid,-start,1,0);
            else
                if(start==1)
                    ans= checkpath(grid,-start,0,1);
                else
                    if(grid.size()==1 && grid[0].size()==1)
                        ans= true;
                    else
                        ans= false;
        }
        
        return ans;
    }
    
    bool checkpath(vector<vector<int>>& grid,int start,int i,int j)
    {
        if(i<0 || i==grid.size() || j<0 || j==grid[i].size())
            return false;
        
        if(dire[grid[i][j]].first!=start && dire[grid[i][j]].second!=start)
            return false;
        
        if(i==grid.size()-1 && j==grid[i].size()-1)
            return true;
        
        int end;
        
        if(dire[grid[i][j]].first==start)
            end=dire[grid[i][j]].second;
        else
            end=dire[grid[i][j]].first;
        
        if(end==-2)
            return checkpath(grid,-end,i+1,j);
        else
            if(end==1)
                return checkpath(grid,-end,i,j+1);
            else
                if(end==2)
                    return checkpath(grid,-end,i-1,j);
                else
                    return checkpath(grid,-end,i,j-1);
    }
};