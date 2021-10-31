// Link To Problem:-
// https://leetcode.com/problems/next-greater-numerically-balanced-number/

// Solution:-

class Solution
{
public:
    int nextBeautifulNumber(int n)
    {
        long long val = n + 1;
        while (val < 7777777)
        {
            if (isValid(val))
                return val;
            val++;
        }

        return 7777777;
    }

    bool isValid(long long val)
    {
        vector<int> count(10, 0);
        // cout<<val<<endl;

        while (val > 0)
        {
            if (val % 10 == 0)
                return false;

            count[val % 10]++;

            if (count[val % 10] > val % 10)
                return false;

            val /= 10;
        }

        for (int i = 0; i < 10; i++)
            if (count[i] == 0)
                continue;
            else if (count[i] != i)
                return false;

        return true;
    }
};