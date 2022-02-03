// Link To Problem:-
// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/

// Solution:-

class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int totalOnes = 0;
        for (auto x : nums)
            if (x == 1)
                totalOnes++;

        int start = 0, currCount = 0, res = 0, n = nums.size();

        while (start < totalOnes)
        {
            if (nums[start])
                currCount++;
            start++;
        }

        res = max(res, currCount);

        while (start < n + totalOnes)
        {
            if (nums[start % n])
                currCount++;
            if (nums[start - totalOnes])
                currCount--;
            start++;

            res = max(res, currCount);
        }

        return totalOnes - res;
    }
};