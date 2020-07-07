// https://leetcode.com/problems/decoded-string-at-index/description/

// Time Complexity:-O(N).
// Space Complexity:-O(1).

class Solution
{
public:
    string decodeAtIndex(string S, int k)
    {
        long size = 0;
        int N = S.size();

        for (int i = 0; i < N; i++)
            if (isdigit(S[i]))
                size *= S[i] - '0';
            else
                size++;

        for (int i = N - 1; i >= 0; i--)
        {
            k %= size;

            if (k == 0 && isalpha(S[i]))
                return (string) "" + S[i];

            if (isdigit(S[i]))
                size /= S[i] - '0';
            else
                size--;
        }

        return "";
    }
};