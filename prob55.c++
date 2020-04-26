// https://leetcode.com/problems/jump-game/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     for each point we will check that from that poisition how much long the ointer can move. If the value found is greater 
// than previous maxpoisition than it will be updated with new one.If the value of i become greater than maxpoisition than it 
// will mean that in real scenerion we can't move more than maxpoisition hence we will terminate the loop and with the condition 
// i==nums.size() return the  desired result thata if it's than it represents the loop reaches end of the array hence we will 
// return true otherwise it represent that the loop does not reachs end of the loop hence we will return false in that condition.

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0;
        
        for(int maxpoisition=0;i<nums.size() && i<=maxpoisition ; i++ )
            maxpoisition=max(maxpoisition , i+nums[i]);
        
        return i==nums.size();
    }
};