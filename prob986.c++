// https://leetcode.com/problems/interval-list-intersections/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     In this what we are doing is that we will make a different vector for result and have two pointers for A and B. 
// Now we will select an interval common for both pointers vector representing and puush it to the result vector than 
// increment the pointer which contains lesser values. 

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        vector<vector<int>> res;
        int i=0,j=0;
        
        while(i<A.size() && j<B.size()) {
            int low=max(A[i][0],B[j][0]);
            int high=min(A[i][1],B[j][1]);
            
            if(low <= high)
                res.push_back({low,high});
            
            if(A[i][1]<B[j][1])
                i++;
            else
                j++;
        }
        
        return res;
        
    }
};