// Link To Problem:-
// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

class Solution
{
public:
    int numberOfSteps(int num)
    {
        int run = 0;
        while (num > 0)
        {
            if (num % 2 == 0)
                num = num / 2;
            else
                num = num - 1;

            run++;
        }

        return run;
    }
};