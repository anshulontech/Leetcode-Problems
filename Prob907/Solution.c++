// Link To Problem:-
// https://leetcode.com/problems/sum-of-subarray-minimums/

// Time Complexity:-O(N).
// Space Complexity:-O(N).

class Solution
{
public:
    int sumSubarrayMins(vector<int> &A)
    {
        stack<int> in_stk_p, in_stk_n;
        int N = A.size();

        vector<int> left(N), right(N);

        for (int i = 0; i < N; i++)
        {
            left[i] = i + 1;
            right[i] = N - i;
        }

        for (int i = 0; i < N; i++)
        {
            while (!in_stk_p.empty() && A[in_stk_p.top()] > A[i])
                in_stk_p.pop();
            left[i] = in_stk_p.empty() ? i + 1 : i - in_stk_p.top();
            in_stk_p.push(i);

            while (!in_stk_n.empty() && A[in_stk_n.top()] > A[i])
            {
                int val = in_stk_n.top();
                in_stk_n.pop();
                right[val] = i - val;
            }

            in_stk_n.push(i);
        }
        int ans = 0, mod = 1e9 + 7;
        for (int i = 0; i < N; i++)
            ans = (ans + A[i] * left[i] * right[i]) % mod;

        return ans;
    }
};