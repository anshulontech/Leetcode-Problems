// https://leetcode.com/problems/shift-2d-grid/

void swap(int *,int *);

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
       vector<int> arr;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                arr.push_back(grid[i][j]);
        if(arr.size()==1)
            return grid;
        while(k>0)
        {
            swap(&arr[arr.size()-1],&arr[0]);
            for(int i=0;i<arr.size()-2;i++)
                swap(&arr[arr.size()-1-i],&arr[arr.size()-2-i]);
            
            k--;
        }
        
        k=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
            {
                grid[i][j]=arr[k];
                k++;
            }
        return grid;
    }
};

void swap(int *p,int *q)
{
    int temp=*p;
    *p=*q;
    *q=temp;
}