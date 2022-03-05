// Link To The Problem:-
// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/

// Solution:-

class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int lastOneCount = 0;

        int res = 0;
        for (auto x : bank)
        {
            int currentOne = 0;

            for (auto y : x)
                if (y == '1')
                    currentOne++;

            if (currentOne == 0)
                continue;

            res += currentOne * lastOneCount;
            lastOneCount = currentOne;
        }

        return res;
    }
};