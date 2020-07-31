// Approach 1:-

class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
        int ans = 1;

        while (n)
        {
            int count = 9;
            int fact = 9;

            for (int i = 2; i <= n; i++, fact--)
                count *= fact;

            ans += count;

            n--;
        }

        return ans;
    }
};