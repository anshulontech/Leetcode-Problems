// Link To Problem:-
// https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/submissions/

// Solution:-

class Solution
{
public:
    int mostWordsFound(vector<string> &sentences)
    {
        int res = 0;

        for (auto &x : sentences)
        {
            int count = 0;

            for (auto y : x)
                if (y == ' ')
                    count++;

            res = max(res, count + 1);
        }

        return res;
    }
};