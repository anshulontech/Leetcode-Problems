// Link To Problem:-
// https://leetcode.com/problems/groups-of-special-equivalent-strings/

string sortitbyparity(string);
void swap(char *, char *);

class Solution
{
public:
    int numSpecialEquivGroups(vector<string> &A)
    {
        int count = 0;
        for (int i = 0; i < A.size(); i++)
            A[i] = sortitbyparity(A[i]);

        for (int i = 0; i < A.size() - 1 && A[i].size() != 0; i++)
            for (int j = i + 1; j < A.size(); j++)
                if (A[i] == A[j])
                {
                    A[i].clear();
                    break;
                }

        for (int i = 0; i < A.size(); i++)
            if (A[i].size() != 0)
                count++;

        return count;
    }
};

string sortitbyparity(string A)
{
    for (int i = 0; i < A.size() - 1; i = i + 2)
        for (int j = i + 2; j < A.size(); j = j + 2)
        {
            if (A[j] < A[i])
                swap(&A[i], &A[j]);
            if (A[j + 1] < A[i + 1])
                swap(&A[i + 1], &A[j + 1]);
        }

    return A;
}

void swap(char *p, char *q)
{
    char temp = *p;
    *p = *q;
    *q = temp;
}