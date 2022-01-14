// Link To Problem:-
// https://leetcode.com/problems/max-increase-to-keep-city-skyline/

class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &A)
    {
        int count = 0;
        vector<int> rowmax;
        vector<int> clmmax;

        for (int i = 0; i < A.size(); i++)
        {
            int max = INT_MIN;
            for (int j = 0; j < A[i].size(); j++)
                if (A[i][j] > max)
                    max = A[i][j];

            rowmax.push_back(max);
        }

        for (int i = 0; i < A[0].size(); i++)
        {
            int max = INT_MIN;
            for (int j = 0; j < A.size(); j++)
                if (A[j][i] > max)
                    max = A[j][i];

            clmmax.push_back(max);
        }

        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < A[0].size(); j++)
            {
                if (A[i][j] != rowmax[i] && A[i][j] != clmmax[j])
                    count = count + min(clmmax[j], rowmax[i]) - A[i][j];
            }

        return count;
    }
};