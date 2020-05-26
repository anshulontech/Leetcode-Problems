// https://leetcode.com/problems/number-of-1-bits/

// Time Complexity:-O(N) Where N is nth poisition of last 1 bit.
// Space Complexity:-O(1).
    
// Approach:-
//     In this we are going to calculate the last bit and checking that is this 1 or not. If it will than we increase 
// the count else just leave the number.

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n) {
            if(n%2==1) 
                count++;
            
            n=n/2;
        }
        
        return count;
    }
};

// Time Complexity:-O(N) Where N is number of 1 bits.
// Space Complexity:-O(1).

// Approach:-
//     Same Approach but faster approach.

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n) {
            n=n&(n-1);            
            count++;
        }
        
        return count;
    }
};