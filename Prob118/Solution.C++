// Link To Problem:-
// https://leetcode.com/problems/pascals-triangle/

// METHOD 1:-

class Solution
{
public:
    vector<vector<int>> generate(int k)
    {
        vector<vector<int>> res;
        if (k == 0)
            return res;
        vector<int> temp;
        temp.push_back(1);
        res.push_back(temp);

        while (k > 1)
        {
            add(res, temp);
            k--;
        }

        return res;
    }

private:
    void add(vector<vector<int>> &res, vector<int> &temp)
    {
        int n = res.size() - 1;
        int m = temp.size();
        int i = 1;

        for (; i < m; i++)
            temp[i] = (res[n][i - 1] + res[n][i]);

        temp.push_back(1);
        res.push_back(temp);
    }
};