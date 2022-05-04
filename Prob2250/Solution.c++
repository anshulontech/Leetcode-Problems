// Link To The Problem:-
// https://leetcode.com/problems/count-number-of-rectangles-containing-each-point/

// Solution:-

class Solution
{
public:
    vector<int> countRectangles(vector<vector<int>> &rectangles, vector<vector<int>> &points)
    {
        vector<vector<int>> arr(101);

        for (auto x : rectangles)
            arr[x[1]].push_back(x[0]);

        for (auto &x : arr)
            sort(x.begin(), x.end());

        int n = points.size();

        vector<int> res(n);

        for (int i = 0; i < n; i++)
        {
            int count = 0;

            for (int j = points[i][1]; j < 101; j++)
            {
                auto &temp = arr[j];

                int idx = lower_bound(temp.begin(), temp.end(), points[i][0]) - temp.begin();

                count += temp.size() - idx;
            }

            res[i] = count;
        }

        return res;
    }
};