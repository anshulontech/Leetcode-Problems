// Link To Problem:-
// https://leetcode.com/problems/jump-game/

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int i = 0;

        for (int maxpoisition = 0; i < nums.size() && i <= maxpoisition; i++)
            maxpoisition = max(maxpoisition, i + nums[i]);

        return i == nums.size();
    }
};