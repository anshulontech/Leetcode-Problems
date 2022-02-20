// Link To The Problem:-
// https://leetcode.com/problems/count-operations-to-obtain-zero/

// Solution:-

class Solution
{
public:
    int countOperations(int num1, int num2)
    {
        int res = 0;

        while (num1 > 0 && num2 > 0)
        {
            res++;
            if (num1 >= num2)
                num1 -= num2;
            else
                num2 -= num1;
        }

        return res;
    }
};