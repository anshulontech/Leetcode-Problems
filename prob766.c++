// https://leetcode.com/problems/toeplitz-matrix/


class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& A) {
        for(int i=0;i<A.size()-1;i++)
            for(int j=0;j<A[i].size()-1;j++)
                if(A[i][j]!=A[i+1][j+1])
                    return 0;
        
        return 1;
    }
};