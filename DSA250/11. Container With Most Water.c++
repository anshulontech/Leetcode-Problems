// Link To The Problem:-
//  https://leetcode.com/problems/container-with-most-water/

// Solution:-

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int res = 0;

        int start = 0, end = height.size() - 1;

        while (start < end)
        {
            res = max(res, (end - start) * (min(height[start], height[end])));

            if (height[start] <= height[end])
                start++;
            else
                end--;
        }

        return res;
    }
};