// Link To Problem:-
// https://leetcode.com/problems/minimum-absolute-difference-queries/

// METHOD 1:-

class Solution
{
public:
    vector<int> minDifference(vector<int> &A, vector<vector<int>> &Q)
    {
        vector<int> ans(Q.size());
        int prefix[100001][101] = {}, cnt[101] = {}, N = A.size(), M = Q.size();
        for (int i = 0; i < N; ++i)
        {
            cnt[A[i]]++;
            for (int j = 1; j < 101; ++j)
                prefix[i + 1][j] = cnt[j];
        }
        for (int i = 0; i < M; ++i)
        {
            int L = Q[i][0], R = Q[i][1], cnt[101] = {};
            for (int j = 0; j < 101; ++j)
                cnt[j] = prefix[R + 1][j] - prefix[L][j];
            int prev = -1, minAbs = INT_MAX;
            for (int j = 1; j < 101; ++j)
            {
                if (cnt[j] == 0)
                    continue;
                if (prev != -1 && j - prev < minAbs)
                    minAbs = j - prev;
                prev = j;
            }
            ans[i] = minAbs == INT_MAX ? -1 : minAbs;
        }
        return ans;
    }
};