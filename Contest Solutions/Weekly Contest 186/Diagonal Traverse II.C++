// Solution:-
class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums)
    {
        unordered_map<int, vector<int>> store;
        int n = nums.size(), maxSum = 0;

        for (int i = 0; i < n; i++)
        {
            int m = nums[i].size();
            maxSum = max(maxSum, i + m - 1);

            for (int j = 0; j < m; j++)
                store[i + j].push_back(nums[i][j]);
        }

        vector<int> res;

        for (int i = 0; i <= maxSum; i++)
        {
            auto &temp = store[i];

            for (int j = temp.size() - 1; j >= 0; j--)
                res.push_back(temp[j]);
        }

        return res;
    }
};