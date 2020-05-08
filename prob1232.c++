// https://leetcode.com/problems/check-if-it-is-a-straight-line/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     We will use the concept of slope here.

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& A) {
        if(A[0][1]==A[1][1])
        {
            for(int i=1;i<A.size()-1;i++)
                if(A[i][1]!=A[i+1][1])
                    return false;
            
            return true;
        }
        
        float dx=A[0][0]-A[1][0];
        float dy=A[0][1]-A[1][1];
        
        float slope=dx/dy;
        
        for(int i=1;i<A.size()-1;i++)
        {
            float dx=A[i][0]-A[i+1][0];
            float dy=A[i][1]-A[i+1][1];
        
            if(dy==0)
                return false;
            
            float help=dx/dy;
            
            if(help!=slope)
                return false;
        }
        
        return true;
        
    }
    
};

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     We will use the concept of cross product here that is if three points are collinear than their cross product will be 
// equal to 0 otherwise they are not collinear.


class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& A) {
        if(A.size()<3)
            return true;
        
        for(int i=0;i<A.size()-2;i++)
            if(cross(A[i],A[i+1],A[i+2])!=0)
                return false;
        
        return true;
    }
    
    int cross(vector<int> & A,vector<int> & B,vector<int> & C)
    {
        int x1=B[0]-A[0];
        int y1=B[1]-A[1];
        int x2=C[0]-B[0];
        int y2=C[1]-B[1];
        
        return x1*y2-x2*y1;
    }
};