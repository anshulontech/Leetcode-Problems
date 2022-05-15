// Link To The Problem:-
//  https://leetcode.com/problems/squares-of-a-sorted-array/

// Solution:-

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> res(n);

        int start = 0, end = n - 1, k = n - 1;

        while (start <= end)
        {
            if (abs(nums[start]) > abs(nums[end]))
            {
                res[k--] = nums[start] * nums[start];
                start++;
            }
            else
            {
                res[k--] = nums[end] * nums[end];
                end--;
            }
        }

        return res;
    }
};