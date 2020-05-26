// https://leetcode.com/problems/reverse-bits/

// Time Complexity:-O(32).
// Space Complexity:-O(1).
    
// Approach:-
//     In a new integer we are going to insert the bits in reverse order that is the ith bit will be inserted at 31-i 
// poisition and return that number.

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        
        
        for(int i=0;i<32;i++) {
            int val=n%2;
            n=n/2;
            res+=val*pow(2,31-i);
        }
        
        return res;
    }
};