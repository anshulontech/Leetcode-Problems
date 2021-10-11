// Link To Problem:-
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/

// METHOD 1:-

class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        int n = nums.size();

        auto itr = nums.begin() + n / 2;

        nth_element(nums.begin(), itr, nums.end());
        int median = *itr;

        int count = 0;

        for (int i = 0; i < nums.size(); i++)
            count += abs(nums[i] - median);

        return count;
    }
};