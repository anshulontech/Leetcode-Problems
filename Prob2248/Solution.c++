// Link To The Problem:-
// https://leetcode.com/problems/intersection-of-multiple-arrays/

// Solution:-

class Solution
{
public:
    vector<int> intersection(vector<vector<int>> &nums)
    {
        int n = nums.size();

        for (auto &x : nums)
            sort(x.begin(), x.end());

        vector<int> res;

        for (int i = 0; i < nums[0].size(); i++)
        {
            bool isAns = true;

            for (int j = 1; j < n; j++)
                if (!isFound(nums[j], nums[0][i]))
                {
                    isAns = false;
                    break;
                }

            if (isAns)
                res.push_back(nums[0][i]);
        }

        return res;
    }

    bool isFound(vector<int> &arr, int val)
    {
        int start = 0, end = arr.size() - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (arr[mid] == val)
                return true;

            if (arr[mid] < val)
                start = mid + 1;
            else
                end = mid - 1;
        }

        return false;
    }
};