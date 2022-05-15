// Link To The Problem:-
//  https://leetcode.com/problems/merge-intervals/

// Solution:-

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &A)
    {
        vector<vector<int>> res;

        sort(A.begin(), A.end());

        int n = A.size();

        for (int i = 0; i < n;)
        {
            int start = A[i][0], end = A[i][1];
            i++;

            while (i < n && end >= A[i][0])
                end = max(end, A[i++][1]);

            res.push_back({start, end});
        }

        return res;
    }
};