// https://leetcode.com/problems/k-th-symbol-in-grammar/description/

class Solution
{
public:
    int kthGrammar(int N, int k)
    {

        if (N == 1)
            return 0;

        if (k % 2 == 0)
            return kthGrammar(N - 1, k / 2) == 0;
        else
            return !(kthGrammar(N - 1, (k + 1) / 2) == 0);
    }
};