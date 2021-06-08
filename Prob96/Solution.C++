// Link To Problem:-
// https://leetcode.com/problems/unique-binary-search-trees/

class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> sol(n + 1, 0);
        sol[0] = 1, sol[1] = 1;

        for (int i = 2; i <= n; i++)
            for (int j = 0; j < i; j++)
                sol[i] += sol[j] * sol[i - j - 1];

        return sol[n];
    }
};