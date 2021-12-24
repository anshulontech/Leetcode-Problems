// Link To Problem:-
// https://leetcode.com/problems/final-value-of-variable-after-performing-operations/

// Solution:-

class Solution
{
public:
    int finalValueAfterOperations(vector<string> &operations)
    {
        int res = 0;

        for (auto &x : operations)
            if (x == "++X" || x == "X++")
                res++;
            else
                res--;

        return res;
    }
};