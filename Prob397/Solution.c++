// LINK TO PROBLEM:-
// https://leetcode.com/problems/integer-replacement/description/

// METHOD 1:-

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
            else if (n == 3 || __builtin_popcount(n + 1) > __builtin_popcount(n - 1))
                n--;
            else
                n++;

            count++;
        }

        return count;
    }
};

// METHOD 2:-

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