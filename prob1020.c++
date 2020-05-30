// https://leetcode.com/problems/number-of-enclaves/

// Time Complexity:-O(N^4).
// Space Complexity:-O(N). For recurssion stack.
    
// Approach:-
//     In this we are first making all the lands which are connected to the boundary into sea, now we will start to 
// traverse the matrix and if found any land than we will just increase the count by 1 and at last the cout is our 
// final answer.

class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        
        if(A.size()==0)
            return 0;
        
        int N=A.size();
        int M=A[0].size();
        
        for(int i=0;i<N;i++)
            if(A[i][0]==1)
                dfs(A,i,0);
        
        
        for(int j=0;j<M;j++)
            if(A[0][j]==1)
                dfs(A,0,j);
        
        for(int i=0;i<N;i++)
            if(A[i][M-1]==1)
                dfs(A,i,M-1);
        
        for(int j=0;j<M;j++)
            if(A[N-1][j]==1)
                dfs(A,N-1,j);
        
        
        int count=0;
        
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                if(A[i][j]==1)
                    count++;
        
        
        return count;
        
    }
    
    void dfs(vector<vector<int>>& A,int i,int j) {
        if(A[i][j]==0)
            return ;
        
        A[i][j]=0;
        
        if(i>0)
            dfs(A,i-1,j);
        if(i<A.size()-1)
            dfs(A,i+1,j);
        if(j>0)
            dfs(A,i,j-1);
        if(j<A[i].size()-1)
            dfs(A,i,j+1);
    }
};