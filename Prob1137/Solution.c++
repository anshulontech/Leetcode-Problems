// Link To Problem:-
// https://leetcode.com/problems/n-th-tribonacci-number/

// Solution:-

class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1 && n == 2)
            return 1;

        int a = 0, b = 1, c = 1;
        int k = 2;

        while (k < n)
        {
            int sum = a + b + c;
            a = b;
            b = c;
            c = sum;

            k++;
        }

        return c;
    }
};