// https://leetcode.com/problems/maximum-subarray/

// Time Complexity:-O(N).
// Space Complexity:-O(1).

// Approach:-
// At the starting we will make two variables named result and temp and initialize them with the first value of the array.
// Now we iterate the whole array starting from the index 1 and change the temp so as to check that the new subarray would 
// start from there or will continue and than update the value of result. At last we return the value of result shows the 
// sum of maximun sun array.

class Solution {
public:
    int maxSubArray(vector<int>& A) {
        if(A.size()==0)
            return INT_MIN;
        
        int result=A[0];
        int temp=A[0];
        for(int i=1;i<A.size();i++)
        {
            temp=max(temp+A[i],A[i]);
            result=max(result,temp);
        }
        
        return result;
    }
};