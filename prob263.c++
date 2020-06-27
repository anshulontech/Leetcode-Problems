// https://leetcode.com/problems/ugly-number/

// Approach:-
//     Just divide by 2, 3 and 5 as often as possible and then check whether we arrived at 1. Also try divisor 4 if 
// that makes the code simpler / less repetitive.

class Solution
{
public:
    bool isUgly(int num)
    {

        if (num < 1)
            return false;

        for (int i = 2; i < 6; i++)
            while (num % i == 0)
                num /= i;

        return num == 1;
    }
};