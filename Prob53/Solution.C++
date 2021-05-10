// Link To Problem:-
// https://leetcode.com/problems/maximum-subarray/

class Solution
{
public:
    int maxSubArray(vector<int> &A)
    {
        if (A.size() == 0)
            return INT_MIN;

        int result = A[0];
        int temp = A[0];
        for (int i = 1; i < A.size(); i++)
        {
            temp = max(temp + A[i], A[i]);
            result = max(result, temp);
        }

        return result;
    }
};