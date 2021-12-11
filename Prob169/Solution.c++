// Link To Problem:-
// https://leetcode.com/problems/majority-element/

// Method 1:-

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int maj = nums[0], count = 1;

        for (int i = 1; i < nums.size(); i++)
            if (nums[i] == maj)
                count++;
            else
            {
                count--;
                if (count == 0)
                {
                    maj = nums[i];
                    count = 1;
                }
                else
                    continue;
            }

        return maj;
    }
};

// METHOD 4:-

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int majority = 0;
        for (unsigned int i = 0, mask = 1; i < 32; i++, mask <<= 1)
        {
            int bits = 0;
            for (int num : nums)
                if (num & mask)
                    bits++;

            if (bits > nums.size() / 2)
                majority |= mask;
        }

        return majority;
    }
};