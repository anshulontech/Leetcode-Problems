// https://leetcode.com/problems/unique-paths/

// Time Complexity:-O(M*N).
// Space Complexity:-O(N*M).
    
// Approach:-
//     Initially we will make a m*n grid which reprsents the number of ways to reach the end if the point you are 
// standing is the strting point. Now lwt us we are at last column or at last row than their are only 1 to mave the 
// last that is move down or move right respectively. Now if we are at point (i,j) than we have two choices that is 
// move right or move down , now if we move down than it represents the value at down index represents number of ways 
// to reach end so we have these ways and if we will move right than number at index represents the number of ways to 
// reach down so we will add both number of way sand store them into the current address and so on we can fill the 
// whole matrix. At last value at starting point represents number of ways to reach end.

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> store(n,vector<int> (m));
        
        for(int i=0;i<n;i++)
            store[i][m-1]=1;
        
        for(int j=0;j<m;j++)
            store[n-1][j]=1;
        
        for(int i=n-2;i>=0;i--)
            for(int j=m-2;j>=0;j--)
                store[i][j]=store[i+1][j]+store[i][j+1];
        
        return store[0][0];
    }
};