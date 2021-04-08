// Link To Problem:-
// https://leetcode.com/problems/4sum/

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> A;
        if (nums.size() < 4)
            return A;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++)
        {
            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                int start = j + 1, end = nums.size() - 1;
                while (start < end)
                {
                    int val = nums[i] + nums[j] + nums[start] + nums[end];
                    if (val < target)
                        start++;
                    else if (val > target)
                        end--;
                    else
                    {
                        A.push_back({nums[i], nums[j], nums[start], nums[end]});
                        int copy1 = nums[start];
                        int copy2 = nums[end];
                        while (start < end && nums[start] == copy1)
                            start++;
                        while (start < end && nums[end] == copy2)
                            end--;
                    }
                }
                while (j + 1 < nums.size() && nums[j + 1] == nums[j])
                    j++;
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                i++;
        }

        return A;
    }
};