// https://leetcode.com/problems/sqrtx/

// Time Complexity:-O(log(N)).
// Space Complexity:-O(N).
    
// Approach:-
//     In this we are going to use the binary search approach for the squar root as mid. If mid is found to be as a squareroot 
//than we assign res equal to mid else if id is found to be less than original square root (check from condition 1.) than 
//we will search for mid in right part else search for mid in left part. Aand so on we can generate the squarroot.

class Solution {
public:
    int mySqrt(int x) {
        int start=1,end=x,res;
        
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            
            if(mid<=x/mid)
            {
                start=mid+1;
                res=mid;
            }
            else
                end=mid-1;
        }
        
        return res;
    }
};