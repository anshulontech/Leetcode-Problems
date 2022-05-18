// Link To The Problem:-
//  https://leetcode.com/problems/4sum/

// Solution:-

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size(), val;
        long long sum;

        vector<vector<int>> res;

        for (int i = 0; i < n;)
        {
            for (int j = i + 1; j < n;)
            {
                int start = j + 1, end = n - 1;

                while (start < end)
                {
                    sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[start] + (long long)nums[end];

                    if (sum == target)
                    {
                        res.push_back({nums[i], nums[j], nums[start], nums[end]});

                        val = nums[start];
                        while (start < end && nums[start] == val)
                            start++;
                        val = nums[end];
                        while (start < end && nums[end] == val)
                            val--;
                    }
                    else if (sum > target)
                        end--;
                    else
                        start++;
                }

                val = nums[j];
                while (j < n && nums[j] == val)
                    j++;
            }
            val = nums[i];
            while (i < n && nums[i] == val)
                i++;
        }

        return res;
    }
};