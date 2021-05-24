// Link To Problem:-
// https://leetcode.com/problems/edit-distance/

// Time Complexity : -O(a *b).
// Space Complexity : -O(a *b).

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int a = word1.size(), b = word2.size();

        vector<vector<int>> store(b + 1, vector<int>(a + 1));

        for (int i = 0; i < b + 1; i++)
            store[i][0] = i;

        for (int j = 0; j < a + 1; j++)
            store[0][j] = j;

        for (int i = 1; i < b + 1; i++)
            for (int j = 1; j < a + 1; j++)
                if (word1[j - 1] != word2[i - 1])
                    store[i][j] = minimum(store[i - 1][j], store[i][j - 1], store[i - 1][j - 1]) + 1;
                else
                    store[i][j] = store[i - 1][j - 1];

        return store[b][a];
    }

    int minimum(int x, int y, int z)
    {
        return min(x, min(y, z));
    }
};