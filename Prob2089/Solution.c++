// Link To Problem:-
// https://leetcode.com/problems/find-target-indices-after-sorting-array/

// Solution:-

class Solution
{
public:
    vector<int> targetIndices(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());

        int start = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        vector<int> res;

        for (int i = start; i < end; i++)
            res.push_back(i);

        return res;
    }
};