// Link To Problem:-
// https://leetcode.com/problems/minimum-moves-to-reach-target-score/

// Solution:-

class Solution
{
public:
    int minMoves(int target, int maxDoubles)
    {
        int res = 0;

        while (target > 1 && maxDoubles > 0)
        {
            if (target % 2 == 1)
            {
                res++;
                target--;
                continue;
            }

            target /= 2;
            res++;
            maxDoubles--;
        }

        res += target - 1;
        return res;
    }
};