// Link To The Problem:-
//  https://leetcode.com/problems/3sum/

// Solution:-

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2;)
        {
            if (nums[i] > 0)
                return res;

            int s = i + 1, e = n - 1, sum, val;

            while (s < e)
            {
                sum = nums[i] + nums[s] + nums[e];

                if (sum == 0)
                {
                    res.push_back({nums[i], nums[s], nums[e]});

                    val = nums[s];
                    while (s < e && nums[s] == val)
                        s++;
                    val = nums[e];
                    while (s < e && nums[e] == val)
                        e--;
                }
                else if (sum > 0)
                    e--;
                else
                    s++;
            }

            val = nums[i];
            while (i < n && nums[i] == val)
                i++;
        }

        return res;
    }
};