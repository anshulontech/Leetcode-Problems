// https://leetcode.com/problems/non-overlapping-intervals/

// Time Complexity:-O(N*Log(N)).
// Space Complexity:-O(1).
    
// Approach:-
//     Initially we will sort the given array with respect to second elemetnt . Now we will traverse the the array and 
// on the case we will find the current element overlaps with the lastValidInterval than we will try to remove it from 
// the array and hence increase the count as their is only need to return the numberof intervals to remove to make it 
// overlap.

class Solution {
private:
    static bool Comp(const vector<int> & A, const vector<int> & B) {
        if(A[1]==B[1])
            return A[0]<B[0];
        
        return A[1]<B[1];
    }
    
    bool overLaps(const vector<int> & A, const vector<int> & B) {
        if(A[0]<B[1])
            return true;
        else
            return false;
    }
    
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),Comp);
        int count=0;
        int lastValidInterval=0;
        for(int i=1;i<intervals.size();i++) 
            if(overLaps(intervals[i],intervals[lastValidInterval]))
                count++;
            else
                lastValidInterval=i;
        
        return count;
    } 
};