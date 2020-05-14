// https://leetcode.com/problems/1-bit-and-2-bit-characters/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     In this what we are going to do is that if the bit represents 1 than we move 2 steps forward else move one step 
// forward. In last the there are 2 conditions which arises like the itterator represents 2nd last index in this is the 
// value to this one is 1 than it represents that it is a case of two-bit else if it is 0 than it represents that it is 
// case of one - bit hence we will retuen true.

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if(bits.size()>1 && bits[bits.size()-1] ==0 && bits[bits.size()-2] ==0)
            return true;
        int i=0;
        int n=bits.size()-2;
        for(;i<n;i++)
            if(bits[i]==1)
                i++;
        
        if(bits[i]==1)
            return false;
        else
            return true;
    }
};