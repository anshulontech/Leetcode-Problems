// Link To Problem:-
// https://leetcode.com/problems/find-peak-element/

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return 0;
        return peaksearch(nums, 0, nums.size() - 1);
    }

    int peaksearch(vector<int> &nums, int start, int end)
    {
        if (start > end)
            return -1;

        int mid = start + (end - start) / 2;

        int left = (mid - 1) < 0 ? INT_MIN : nums[mid - 1];
        int right = (mid + 1) > (nums.size() - 1) ? INT_MIN : nums[mid + 1];

        if (nums[mid] > right && nums[mid] > left)
            return mid;

        if (mid > 0 && nums[mid - 1] > nums[mid])
            return peaksearch(nums, start, mid - 1);
        else
            return peaksearch(nums, mid + 1, end);
    }
};