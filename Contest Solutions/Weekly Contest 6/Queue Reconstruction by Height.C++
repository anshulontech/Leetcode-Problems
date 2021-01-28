// Solution:-

class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &A)
    {
        vector<vector<int>> res;

        sort(A.begin(), A.end(), [](const vector<int> &a, const vector<int> &b) {
            return (a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]));
        });

        for (vector<int> &x : A)
            res.insert(res.begin() + x[1], x);

        return res;
    }
};