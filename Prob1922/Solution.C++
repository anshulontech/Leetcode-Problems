// Link To Problem:-
// https://leetcode.com/problems/count-good-numbers/

// METHOD 1:-

class Solution
{
    long long mod = 1e9 + 7;

public:
    int countGoodNumbers(long long n)
    {
        return (power(n - n / 2, 5) * power(n / 2, 4)) % mod;
    }

    long long power(long long k, long long val)
    {
        if (k == 0)
            return 1;

        long long halfRes = power(k / 2, val);
        if (k % 2 == 0)
            return (halfRes * halfRes) % mod;
        else
            return (((halfRes * halfRes) % mod) * val) % mod;
    }
};