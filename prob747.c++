// https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/

// Time Complexity:-O(N).
// Space Compexity:-O(1).

// Approach:-  Two Pass O(N).
//     We will check that is the condition is fulfilled by these pairs or not , if it is that it will satisfy this
// for all pairs and hence we will return the index of the largest element but if it fails to do so than this property
// doesn't hold for the array and hence in that case we will return -1 .

class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        int firstL = 0;
        int secondL = 0;

        int index = -1;

        for (int i = 0; i < nums.size(); i++)
            if (firstL < nums[i])
            {
                firstL = nums[i];
                index = i;
            }

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > secondL && nums[i] < firstL)
                secondL = nums[i];

        return firstL >= secondL * 2 ? index : -1;
    }
};

// Approach:- One Pass O(N).
//     Same as that of above one.

class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        int index = -1, max_val = -1, second_max = -1;

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > max_val)
            {
                second_max = max_val;
                max_val = nums[i];
                index = i;
            }
            else if (nums[i] > second_max)
                second_max = nums[i];

        return max_val >= second_max * 2 ? index : -1;
    }
};