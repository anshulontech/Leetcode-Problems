// Link To Problem:-
// https://leetcode.com/problems/implement-strstr/

class Solution
{
public:
    int strStr(string A, string B)
    {
        if (B.size() == 0)
            return 0;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] == B[0])
            {
                int k = 0;
                while (i < A.size() && k < B.size() && A[i + k] == B[k])
                    k++;

                if (k == B.size())
                    return i;
            }
        }

        return -1;
    }
};