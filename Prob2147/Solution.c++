// Link To Problem:-
// https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/

// Solution:-

class Solution
{
public:
    int numberOfWays(string corridor)
    {
        int sCount = 0;

        vector<int> temp;

        int count = 0, n = corridor.size(), aCount = 0;

        for (int i = 0; i < n; i++)
        {
            if (corridor[i] == 'S')
                sCount++, count++;

            if (count == 2)
            {
                i++;
                aCount = 0;
                while (i < n && corridor[i] == 'P')
                    aCount++, i++;
                i--;
                if (i == n - 1)
                    if (aCount)
                        temp.push_back(1);
                    else
                        temp.push_back(1);
                else
                    temp.push_back(aCount + 1);

                count = 0;
            }
        }

        if (temp.size() == 0 || sCount % 2 == 1)
            return 0;

        long long res = 1, mod = 1e9 + 7;

        for (auto x : temp)
        {
            res *= x;
            res %= mod;
        }

        return res;
    }
};