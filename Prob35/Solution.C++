// Link To Problem:-
// https://leetcode.com/problems/search-insert-position/

// Approach 1:-

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] >= target)
                return i;

        return nums.size();
    }
};

// Approach 2:-

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int start = 0, end = nums.size() - 1, mid;

        while (start <= end)
        {
            mid = start + (end - start) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }

        return start;
    }
};
