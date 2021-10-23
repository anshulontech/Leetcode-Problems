// Link To Problem:-
// https://leetcode.com/problems/number-of-1-bits/

// METHOD 1:-

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        while (n)
        {
            if (n % 2 == 1)
                count++;

            n = n / 2;
        }

        return count;
    }
};

// METHOD 2 : -

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        while (n)
        {
            n = n & (n - 1);
            count++;
        }

        return count;
    }
};