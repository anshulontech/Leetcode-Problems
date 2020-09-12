// Approach 1:-

class Solution
{
private:
    int target, limit;
    vector<int> temp;
    vector<vector<int>> res;

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        target = n, limit = k;

        for (int i = 1; i < 10; i++)
        {
            int sum = i;
            temp.push_back(i);
            backTrack(sum, i, 1);
            temp.pop_back();
        }

        return res;
    }

    void backTrack(int sum, int last, int size)
    {
        if (size > limit || sum > target)
            return;

        if (sum == target && size == limit)
        {
            res.push_back(temp);
            return;
        }

        for (int i = last + 1; i < 10; i++)
        {
            sum += i;
            temp.push_back(i);
            backTrack(sum, i, size + 1);
            sum -= i;
            temp.pop_back();
        }

        return;
    }
};