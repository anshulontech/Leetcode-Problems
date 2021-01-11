// Link To Problem:-
// https://leetcode.com/problems/calculate-money-in-leetcode-bank/

// Solution:-

class Solution
{
public:
    int totalMoney(int n)
    {
        int res = 0;
        int temp = n / 7;
        int count = 1;
        while (temp)
        {
            long long val = 7 * (count + 3);
            res += val;
            count++;
            temp--;
        }

        int k = n % 7;

        for (int i = n / 7 + 1, j = 0; j < k; j++, i++)
            res += i;

        return res;
    }
};