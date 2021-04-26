// Link To Problem:-
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> A;
        int start = 0, end = nums.size() - 1;
        int mid, flag = 0;

        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (target == nums[mid])
            {
                flag = 1;
                break;
            }

            if (target < nums[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }

        if (flag == 0)
        {
            A.push_back(-1);
            A.push_back(-1);
            return A;
        }
        else
        {
            int mid1 = mid;
            while (mid > 0 && nums[mid] == nums[mid - 1])
                mid--;
            while (mid1 < nums.size() - 1 && nums[mid1] == nums[mid1 + 1])
                mid1++;

            A.push_back(mid);
            A.push_back(mid1);
            return A;
        }

        return A;
    }
};
