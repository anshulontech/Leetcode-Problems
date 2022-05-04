// Link To The Problem:-
// https://leetcode.com/problems/number-of-flowers-in-full-bloom/

// Solution:-

class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &persons)
    {
        vector<int> start, end;

        for (auto x : flowers)
        {
            start.push_back(x[0]);
            end.push_back(x[1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        vector<int> res;

        for (auto x : persons)
        {
            int on = upper_bound(start.begin(), start.end(), x) - start.begin();
            int off = lower_bound(end.begin(), end.end(), x) - end.begin();

            res.push_back(on - off);
        }

        return res;
    }
};