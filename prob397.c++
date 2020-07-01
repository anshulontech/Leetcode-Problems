// https://leetcode.com/problems/integer-replacement/description/

// Time Complexity:-O(log(n)).
// Space Complexity:-O(1).
    
// Approach:-
//     If the n is even than we will just divide it with 2 and increase count by 1. But if n is odd than we will first 
// check that whether n+1 or n-1 contains less number of 1 as bit, and make the n towards that one. If both gives tie 
// than we will also increase the number .

class Solution {
public:
    int integerReplacement(int n) {
        if(n==INT_MAX)
            return 32;
        int count=0;
        
        while(n!=1) {
            if(n%2==0)
                n/=2;
            else
                if(n==3 || __builtin_popcount(n+1)>__builtin_popcount(n-1))
                    n--;
                else
                    n++;
            
            count++;
        }
        
        return count;
    }
};

// Doing bitCount on every iteration is not the best way.It is enough to examine the last two digits to figure out 
// whether incrementing or decrementing will give more 1's. Indeed, if a number ends with 01, then certainly decrementing 
// is the way to go.Otherwise, if it ends with 11, then certainly incrementing is at least as good as decrementing
// (*011->* 010 / *100) or even better(if there are three or more 1's).This leads to the following solution :

    class Solution
{
public:
    int integerReplacement(int n)
    {
        if (n == INT_MAX)
            return 32;
        int count = 0;

        while (n != 1)
        {
            if (n % 2 == 0)
                n /= 2;
            else if (n == 3 || ((n >> 1) & 1) == 0)
                n--;
            else
                n++;

            count++;
        }

        return count;
    }
};