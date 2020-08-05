// Approach 1:-

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &A)
    {
        int res = 0;
        int N = A.size() - 2;

        for (int i = 0; i < N;)
        {
            int prev = i;
            int diff = A[i + 1] - A[i];

            while (i < A.size() - 1 && A[i + 1] - A[i] == diff)
                i++;

            if (i > prev + 1)
                res += (i - prev) * (i - prev - 1) / 2;
        }

        return res;
    }
};