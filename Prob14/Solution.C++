// Link To Problem:-
// https://leetcode.com/problems/longest-common-prefix/

class Solution
{
public:
    string longestCommonPrefix(vector<string> &A)
    {
        if (A.size() == 0)
        {
            string s;
            return s;
        }
        for (int i = 1; i < A.size(); i++)
        {
            int k = 0;
            while (k < A[0].size() && k < A[i].size() && A[0][k] == A[i][k])
                k++;

            if (k != A[0].size())
            {
                A[0] = A[0].substr(0, k);
            }

            if (A[0].size() == 0)
                return A[0];
        }

        return A[0];
    }
};