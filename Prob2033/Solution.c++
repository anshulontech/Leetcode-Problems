// Link To Problem:-
// https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/

// Solution:-

class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {
        vector<int> arr;

        for (auto x : grid)
            for (auto y : x)
                arr.push_back(y);

        sort(arr.begin(), arr.end());

        int n = grid.size(), m = grid[0].size();

        int t = arr[n * m / 2], ans = 0;

        for (int i = 0; i < n * m; i++)
            if (abs(arr[i] - t) % x != 0)
                return -1;
            else
                ans += abs(arr[i] - t) / x;

        return ans;
    }
};