// https://leetcode.com/problems/valid-mountain-array/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     From the 0th index we are running the loop untill condition 1 will not become false which runs untill the starting part 
// is a strictly increasing part and same condition is applied for end part for strictly decreasing array. if the condition 3 
// is satisfied than we return true else return false. Condition 3 tells that the extreme are not aprt of mountain peak and 
// their is only one peak in the mountain.

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size()<3)
            return false;
        
        int start=0,end=A.size()-1;
        
        while(start<A.size()-1 && A[start]<A[start+1]) // conition 1  for strictly increasing check
            start++;
        while(end>0 && A[end]<A[end-1])  // condition 2. for strictly decreasing check
            end--;
        
        return start>0 && start==end && end<A.size()-1; // Condition 3.
        
    }
};