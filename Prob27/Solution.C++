// Link To Problem:-
// https://leetcode.com/problems/remove-element/

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == val)
            {
                nums.erase(nums.begin() + i, nums.begin() + i + 1);
                i--;
            }

        return nums.size();
    }
};