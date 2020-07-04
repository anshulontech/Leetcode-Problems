// https://leetcode.com/problems/combinations/description/

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> temp;

public:
    vector<vector<int>> combine(int n, int k)
    {
        if (temp.size() == (k - 1))
        {
            int i = 0;
            makeCombination(i, n);
        }
        else
            for (int i = 1; i <= n; i++)
            {
                temp.push_back(i);
                helper(i, k, n);
                temp.pop_back();
            }

        return res;
    }

    void helper(int &index, int &k, int &n)
    {
        if (temp.size() == (k - 1))
            makeCombination(index, n);
        else
            for (int i = index + 1; i <= n; i++)
            {
                temp.push_back(i);
                helper(i, k, n);
                temp.pop_back();
            }

        return;
    }

    void makeCombination(int &index, int &n)
    {

        for (int i = index + 1; i <= n; i++)
        {
            temp.push_back(i);
            res.push_back(temp);
            temp.pop_back();
        }

        return;
    }
};