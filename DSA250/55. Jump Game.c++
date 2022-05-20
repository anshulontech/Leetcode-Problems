// Link To The Problem:-
//  https://leetcode.com/problems/jump-game/

// Solution:-

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {

        int maxIdx = 0, n = nums.size();

        for (int i = 0; i < n && i <= maxIdx; i++)
        {
            if (nums[i] + i >= (n - 1))
                return true;

            maxIdx = max(maxIdx, nums[i] + i);
        }
        return false;
    }
};