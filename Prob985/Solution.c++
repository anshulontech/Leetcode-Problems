// Link To Problem:-
// https://leetcode.com/problems/sum-of-even-numbers-after-queries/

class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &A, vector<vector<int>> &B)
    {
        vector<int> D;
        int sum = 0;
        for (int i = 0; i < A.size(); i++)
            if (A[i] % 2 == 0)
                sum = sum + A[i];

        for (int i = 0; i < B.size(); i++)
        {
            int index = B[i][1];
            A[index] = A[index] + B[i][0];

            if ((A[index] - B[i][0]) % 2 == 0)
                if (A[index] % 2 == 0)
                    sum = sum + B[i][0];
                else
                    sum = sum - A[index] + B[i][0];
            else if (A[index] % 2 == 0)
                sum = sum + A[index];

            D.push_back(sum);
        }

        return D;
    }
};