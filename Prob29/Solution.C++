// Link To Problem:-
// https://leetcode.com/problems/divide-two-integers/

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        long dvd = labs(dividend), div = labs(divisor);
        long res = 0;

        while (dvd - div >= 0)
        {
            long temp = div, m = 1;
            while (temp << 1 <= dvd)
            {
                temp = temp << 1;
                m = m << 1;
            }

            dvd -= temp;
            res += m;
        }

        return res * sign;
    }
};