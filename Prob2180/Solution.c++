// Link To The Problem:-
// https://leetcode.com/problems/count-integers-with-even-digit-sum/

// Solution:-

class Solution
{
public:
    int countEven(int num)
    {
        int res = 0;

        for (int i = 1; i <= num; i++)
            if (isEvenDigitSum(i))
                res++;

        return res;
    }

    bool isEvenDigitSum(int num)
    {
        int sum = 0;

        while (num)
        {
            sum += num % 10;
            num /= 10;
        }

        return sum % 2 == 0;
    }
};