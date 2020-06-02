// https://leetcode.com/problems/factorial-trailing-zeroes/

// Time Complexity:-O(log(n)).
// Space Complexity:-O(1).
    
// Approach :-
//     In this we are going to calculate the total number of factors as 5 in n! using the thing that to calculate no 
// of factors divide the nubmber with 5 and add quotient to res and do the same thing for the new number obtained . 
// So what happened by doing this way is that first you calculate total number of number having factore 5 than 
// calculate nubers havng factor 5*5 and so on.

class Solution {
public:
    int trailingZeroes(int num) {
        int count=0;
        while(num>=5) {
            count+=num/5;
            num/=5;
        }
        
        return count;
    }
};