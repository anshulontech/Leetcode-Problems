// Link To The Problem:-
//  https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// Solution:-

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0, j = 0, n = nums.size();

        while (i < n)
        {
            int val = nums[i];
            nums[j] = val;
            while (i < n && nums[i] == val)
                i++;
            j++;
        }

        return j;
    }
};