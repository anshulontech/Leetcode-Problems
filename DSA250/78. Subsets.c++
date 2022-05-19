// Link To The Problem:-
//  https://leetcode.com/problems/subsets/

// Solution:-

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;

        int n = nums.size();

        vector<int> temp;

        dfs(nums, temp, res, 1, n);

        temp.push_back(nums[0]);

        dfs(nums, temp, res, 1, n);

        return res;
    }

    void dfs(vector<int> &nums, vector<int> &temp, vector<vector<int>> &res, int idx, int &n)
    {
        if (idx == n)
        {
            res.push_back(temp);
            return;
        }

        dfs(nums, temp, res, idx + 1, n);

        temp.push_back(nums[idx]);

        dfs(nums, temp, res, idx + 1, n);

        temp.pop_back();
    }
};