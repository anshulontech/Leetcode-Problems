// Solution:-

class Solution
{
public:
    int maxRotateFunction(vector<int> &A)
    {
        int n = A.size();

        long long sum = 0;
        long long currSum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += A[i];
            currSum += (A[i] * i);
        }

        long long max_sum = currSum;

        for (int i = 0; i < n; i++)
        {
            currSum += (A[i] * (n - 1)) - sum + A[i];
            max_sum = max(max_sum, currSum);
        }

        return max_sum;
    }
};