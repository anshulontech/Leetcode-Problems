// Link To The Problem:-
//  https://leetcode.com/problems/combination-sum/

// Solution:-

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &arr, int target)
    {
        vector<vector<int>> res;
        int n = arr.size();

        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++)
        {
            int sum = arr[i];
            vector<int> temp;
            temp.push_back(arr[i]);

            dfs(arr, sum, target, res, temp, i, n);
        }

        return res;
    }

    void dfs(vector<int> &arr, int &sum, int &target, vector<vector<int>> &res, vector<int> &temp, int idx, int &n)
    {
        if (sum > target)
            return;

        if (sum == target)
            res.push_back(temp);

        for (int i = idx; i < n; i++)
        {
            sum += arr[i];
            temp.push_back(arr[i]);
            dfs(arr, sum, target, res, temp, i, n);
            temp.pop_back();
            sum -= arr[i];
        }
    }
};