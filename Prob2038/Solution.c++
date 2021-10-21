// Link To Problem:-
// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/

// Solution:-

class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        int alice = 0, bob = 0;
        int count1 = 0, count2 = 0;

        for (auto x : colors)
        {
            if (x == 'A')
            {
                count1++;
                if (count2 > 2)
                    bob += count2 - 2;

                count2 = 0;
            }
            else
            {
                count2++;
                if (count1 > 2)
                    alice += count1 - 2;

                count1 = 0;
            }
        }

        if (count2 > 2)
            bob += count2 - 2;
        if (count1 > 2)
            alice += count1 - 2;

        return alice > bob;
    }
};