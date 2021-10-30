// Link To Problem:-
// https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

// METHOD 1:-

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            nums[abs(nums[i]) - 1] *= -1;

            if (nums[abs(nums[i]) - 1] > 0)
                res.push_back(abs(nums[i]));
        }

        return res;
    }
};