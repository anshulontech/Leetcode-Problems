// https://leetcode.com/problems/sum-of-square-numbers/

//Method 1:-

// Time Complexity:-O(sqrt(n)).
// Space Complexity:-O(1).
    
// Approach:-
//     Starting from 0 we will check that if a number equal to c-a*a is found to be a perfect square than we will return true.

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i=0;i<=sqrt(c);i++)
        {
            int x=sqrt(c-i*i);
            if(x*x==(c-i*i))
                return true;
        }
        
        return false;
    }
};


//Method 2:-

// Time Complexity:-O(sqrt(n)).
// Space Complexity:-O(1).
    


// Approch:-
//     Using fermet theorem according to which Any positive number nn is expressible as a sum of two squares if and only 
//if the prime factorization of nn, every prime of the form (4k+3)(4k+3) occurs an even number of times.

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i=2;i*i<=c;i++)
        {
            int count=0;
            if(c%i==0)
            {
                while(c%i==0)
                {
                    count++;
                    c/=i;
                }
                
                if(i%4==3 && count%2!=0)
                    return false;
            }
        }
        
        return c%4 != 3;
    }
};