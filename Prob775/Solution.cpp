// Approach 1:-

class Solution
{
public:
    bool isIdealPermutation(vector<int> &A)
    {
        for (int i = 0; i < A.size(); i++)
            for (int j = i + 2; j < A.size(); j++)
                if (A[i] > A[j])
                    return false;

        return true;
    }
};

// Approach 2:-

class Solution
{
public:
    bool isIdealPermutation(vector<int> &A)
    {
        int max_val = -1;

        int N = A.size() - 2;

        for (int i = 0; i < N; i++)
        {
            max_val = max(max_val, A[i]);

            if (max_val > A[i + 2])
                return false;
        }

        return true;
    }
};

// Approach 3:-

class Solution
{
public:
    bool isIdealPermutation(vector<int> &A)
    {
        for (int i = 0; i < A.size(); i++)
            if (abs(A[i] - i) > 1)
                return false;

        return true;
    }
};