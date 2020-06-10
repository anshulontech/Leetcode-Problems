// https://leetcode.com/problems/search-insert-position/

Time Complexity:-O(N).
Space Complexity:-O(1).

Approach:-
    In this we are itterating the array from 0th and on situation when the current value is found to be greater than 
or equal to target than in that case we will return that index.

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++)
            if(nums[i]>=target)
                return i;
        
        return nums.size();
    }
};

Time Complexity:-O(Log(N)).
Space Complexity:-O(1).

Approach:-
    Use the concept of binary search.

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