// Link To The Problem:-
//  https://leetcode.com/problems/find-the-duplicate-number/

// Solution 1:-

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {

        for (auto x : nums)
        {
            if (nums[abs(x)] < 0)
                return abs(x);

            nums[abs(x)] *= -1;
        }

        return -1;
    }
};

// Solution 2:-

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();

        int slow = nums[0], fast = nums[0];

        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = nums[0];

        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
