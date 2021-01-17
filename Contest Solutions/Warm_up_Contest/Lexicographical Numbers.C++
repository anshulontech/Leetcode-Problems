// Solution:-

class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> res;

        for (int i = 1; i < 10; i++)
        {
            if (i > n)
                break;
            res.push_back(i);
            dfs(res, i, n);
        }

        return res;
    }

private:
    void dfs(vector<int> &res, int num, int &n)
    {
        for (int i = 0; i < 10; i++)
            if (num * 10 + i > n)
                break;
            else
            {
                res.push_back(num * 10 + i);
                dfs(res, num * 10 + i, n);
            }
    }
};