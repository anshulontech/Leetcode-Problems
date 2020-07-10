// https://leetcode.com/problems/rectangle-overlap/description/

// Time Complexity:-O(1).
// Space Complexity:-O(1).
    
// Approach:-
//     We will find tht if the two rectangles are left or right or top or down to other is or not, if they were anyone 
// of the than they we never overlap and hence we will return false else return true.

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return ! ((rec1[0]>=rec2[2]) || (rec1[2]<=rec2[0]) || (rec1[1]>=rec2[3]) || (rec1[3]<=rec2[1])) ;
    }
};