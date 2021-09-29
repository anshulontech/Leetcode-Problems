// Link To Problem:-
// https://leetcode.com/problems/sort-array-by-parity-ii/

// Solution:-

void swap(int *, int *);

class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &A)
    {
        for (int i = 0; i < A.size(); i++)
            if (i % 2 == 0)
            {
                int j = i;
                while (A[j] % 2 != 0)
                    j++;
                if (j == A.size())
                    j--;
                swap(&A[i], &A[j]);
            }
            else
            {
                int j = i;
                while (A[j] % 2 == 0)
                    j++;
                if (j == A.size())
                    j--;
                swap(&A[i], &A[j]);
            }

        return A;
    }
};

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}