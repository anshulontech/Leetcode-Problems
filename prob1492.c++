// https://leetcode.com/problems/the-kth-factor-of-n/description/

// Time Complexity:-O(N).
// Space Complexity:-O(1).
    
// Approach:-
//     In this what we are going to do is that we will run a loop from i=1 till n-1 and in the way we are checking 
// that is a factor of n . If it is than we will increase our count and when count reaches k we will break the loop 
// and return the last factor . If the loop terminates by itself before count become equal to k than in that situation 
// we will return false.

class Solution {
public:
    int kthFactor(int n, int k) {
        int count=0;
        int i=1;
        for(;i<=n&& count<k;i++)
            if(n%i==0)
                count++;
        
        if(count==k)
            return i-1;
        else
            return -1;
    }
};