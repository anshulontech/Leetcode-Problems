// Link To Problem:-
// https://leetcode.com/problems/factorial-trailing-zeroes/

// METHOD 1:-

class Solution
{
public:
    int trailingZeroes(int num)
    {
        int count = 0;
        while (num >= 5)
        {
            count += num / 5;
            num /= 5;
        }

        return count;
    }
};