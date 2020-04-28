// https://leetcode.com/problems/maximal-square/

// Time Complexity:-O(N*M).
// Space Complexity:-O(N*M).
    
// Approach:-
//     We will first convert the table into integer form. Now from point(1,1) we will find that is that point will make a 
// square upwards. If yes than we will check that just at point (i-1,j-1) is any square exist or not if there i one also than 
// we will update the cooridiantes of (i,j) according to step 1 by checking that is the square exist with these or not. At last 
// we will return the square of max as this represents the number of sides of max square that can form.Else the code is clear 
// and easy to understandable.

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        vector<vector<int>> store(matrix.size(),vector<int>(matrix[0].size()));
        
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[i].size();j++)
                store[i][j]=matrix[i][j]-'0';
        
        int max=0;
        for(int i=0;i<matrix[0].size();i++)
            if(store[0][i]==1)
            {
                max=1;
                break;
            }
        if(max==0)
            for(int i=0;i<matrix.size();i++)
                if(store[i][0]==1)
                {
                    max=1;
                    break;
                }
        for(int i=1;i<matrix.size();i++)
            for(int j=1;j<matrix[i].size();j++)
                if(store[i][j]==1 )
                    if(store[i-1][j]!=0 && store[i][j-1]!=0 && store[i-1][j-1]!=0)
                    {
                        int val=min(store[i-1][j-1],store[i][j-1]);// Step 1
                        val=min(val,store[i-1][j]); // step 1
                        store[i][j]=val+1;
                        if(store[i][j]>max)
                            max=store[i][j];
                    }
                    else
                        if(max<1)
                            max=1;
        
        return max*max;
    }
};