// Link To The Problem:-
// https://leetcode.com/problems/number-of-ways-to-buy-pens-and-pencils/

// Solution:-

class Solution
{
public:
    long long waysToBuyPensPencils(long long total, long long cost1, long long cost2)
    {
        long long res = 0;

        long long pensCost = 0;

        while (pensCost <= total)
        {
            long long leftAmount = total - pensCost;
            long long quantity = leftAmount / cost2;

            res += quantity + 1;
            pensCost += cost1;
        }

        return res;
    }
};