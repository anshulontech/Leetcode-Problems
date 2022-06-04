// Link To The Problem:-
//  https://leetcode.com/problems/counting-bits/

// Solution:-

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> res(n + 1, 0);

        if (n == 0)
            return res;

        res[1] = 1;

        int prev = 2;

        for (int i = 2; i <= n;)
        {
            for (int j = 0; j < prev && i <= n; i++, j++)
                res[i] = 1 + res[j];
            prev = i;
        }

        return res;
    }
};