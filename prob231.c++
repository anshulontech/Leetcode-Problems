// https://leetcode.com/problems/power-of-two/

// Time Complexity:-O(log(n)).
// Space Complexity:-O(1).

// Approach:-
//     We will divide n with 2 till n will not become 1 and if any any stager where n is greater than 1 and not divisible 
// by 2 than we will return false else return true if it reaches end of the loop.

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<1)
            return false;
        while(n>1) {
            if(n%2!=0)
                return false;
            
            n/=2;
        }
        
        return true;
    }
};