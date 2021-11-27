// Link To Problem:-
// https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/

// METHOD 1:-

class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &A, int k)
    {
        if (A.size() == 0)
            return NULL;
        sort(A.begin(), A.end());
        int sum = 0;

        for (int i = 0; i < A.size(); i++)
        {
            if (k > 0 && A[i] <= 0)
            {
                A[i] = -A[i];
                k--;
            }

            sum += A[i];
        }

        if (k % 2 == 0)
            return sum;
        else
        {
            sort(A.begin(), A.end());
            return sum -= (2 * A[0]);
        }
    }
};

// METHOD 2:-

int min(vector<int> &);

class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &A, int k)
    {
        if (A.size() == 0)
            return NULL;
        sort(A.begin(), A.end());
        int sum = 0;

        for (int i = 0; i < A.size(); i++)
        {
            if (k > 0 && A[i] < 0)
            {
                A[i] = -A[i];
                k--;
            }
            sum += A[i];
        }
        if (k % 2 == 0)
            return sum;
        else
            return sum - min(A) * 2;
    }
};

int min(vector<int> &A)
{
    int min = INT_MAX;
    for (int i = 0; i < A.size(); i++)
        if (A[i] < min)
            min = A[i];

    return min;
}